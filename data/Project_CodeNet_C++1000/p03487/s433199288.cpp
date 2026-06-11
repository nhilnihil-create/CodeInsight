#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    
    map<int,int> m;
    REP(i,N){
        m[a[i]] += 1;
    }
    
    int ans = 0;
    for ( auto itr = m.begin(); itr != m.end(); ++itr ){
        int X = itr->first, Xnum = itr->second;
        //cout << X << " " << Xnum << endl;
        if ( X < Xnum ) {
            ans += ( Xnum - X );
        } else if ( X > Xnum ){
            ans += Xnum;
        }
    }
    cout << ans << endl;
    return 0;
}