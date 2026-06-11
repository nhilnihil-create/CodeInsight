#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(const string& S, const vector<pair<char, int>>& query){
    int L = -1, R = S.size();
    while(R-L > 1){
        int mid = (L+R)/2;
        int pos = mid;
        for(auto& q : query){
            if(S[pos] != q.first) continue;
            pos += q.second;
            if(pos < 0 || S.size() <= pos) break;
        }
        if(pos < 0) L = mid;
        else R = mid;
    }
    return L + 1;
}

int main(){
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    vector<pair<char, int>> query;
    for(int i=0;i<Q;i++){
        string t, d; cin >> t >> d;
        query.emplace_back(t[0], d[0]=='R'?1:-1);
    }
    int res = N - solve(s, query);
    reverse(s.begin(), s.end());
    for(auto& q : query) q.second = -q.second;
    res -= solve(s, query);
    cout << res << endl;
}