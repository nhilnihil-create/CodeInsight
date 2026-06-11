#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long ;
using P = pair<int, int>;

void solver(int N, string S, int &ans){

    map<char, int> l;
    map<char, int> r;
    int buf{};

    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= i; ++j){
            l[S.at(j)]++;
        }
        for(int k = i+1; k != N; ++k){
            r[S.at(k)]++;
        }

        for(auto p: l){
            auto word = p.first;
            if(r.count(word) != 0) ++buf;
        }
        ans = max(ans, buf);

        buf = 0;
        l.clear();
        r.clear();
    }

    return;
}


int main(){

    int N;
    string S;
    cin >> N >> S;

    int ans = -1;
    solver(N, S, ans);
    cout << ans << endl;

    return 0;
}