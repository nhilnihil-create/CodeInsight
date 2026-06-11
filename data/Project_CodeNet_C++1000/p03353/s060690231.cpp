#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
 
int main() {
    string s;
    int K;
    cin >> s >> K;
    vector<string> subStrs;
    int n = s.size();
    for (int i=0; i<n; i++) {
        for (int j=1; j<=5; j++) {
            subStrs.push_back(s.substr(i, j));
        }
    }
    map<string, int> mp;
    rep(i, subStrs.size()) mp[subStrs[i]]++;
    int cnt = 1;
    for(auto p: mp) {
        if (cnt == K) {
            cout << p.first << endl;
            break;
        }
        cnt++;
    }
    return 0;
}