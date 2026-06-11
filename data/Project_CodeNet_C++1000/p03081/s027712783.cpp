#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define debug(x) cout << #x << " = " << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    
    int N, Q; cin >> N >> Q;
    vector<char> s(N + 2), t(Q), d(Q);
    rep(i, N)cin >> s[i + 1];
    rep(i, Q)cin >> t[i] >> d[i];
    s[0] = s[N + 1] = '*';

    int ll = 0, lr = N + 1;
    while(lr - ll > 1){
        int m = (ll + lr) / 2;
        int pos = m;
        rep(i, Q){
            if(t[i] == s[pos]){
                if(d[i] == 'R')pos++;
                else pos--;
            }
        }
        if(pos == 0)ll = m;
        else lr = m;
    }

    int rl = 0, rr = N + 1;
    while(rr - rl > 1){
        int m = (rl + rr) / 2;
        int pos = m;
        rep(i, Q){
            if(t[i] == s[pos]){
                if(d[i] == 'R')pos++;
                else pos--;
            }
        }
        if(pos == N + 1)rr = m;
        else rl = m;
    }

    cout << rl - lr + 1<< endl;
    return 0;
    
}