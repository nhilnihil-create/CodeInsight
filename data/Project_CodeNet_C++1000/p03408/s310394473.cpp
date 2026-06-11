#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int N,M;
    cin >> N;
    vector<string> s(N);
    REP(i,N) cin >> s[i];
    cin >> M;
    vector<string> t(M);
    REP(i,M) cin >> t[i];
    
    map <string,int> m;
    REP(i,N){
        m[s[i]] = m[s[i]] + 1;
    }
    REP(i,M){
        m[t[i]] = m[t[i]] - 1;
    }
    int ans = 0;
    for ( auto a: m){
        int x = a.second;
        chmax(ans,x);
    }
    cout << ans << endl;
    
    return 0;
}
