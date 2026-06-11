#include <bits/stdc++.h>
#define int long long
#define P(x) {if (debug) cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define D(i,n) for (int i=(n); i-->0;)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define MA(a,v) a = max(a,v)
#define V vector
#define pb push_back
#define mt make_tuple
using namespace std;
template<class T> ostream& operator<<(ostream& os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i]; return os;}
const bool debug = 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t; cin>>s;
    t = s; reverse(ALL(t));
    int n = S(s);
    int k; cin>>k;
    V<V<V<int>>> lcs(n+1, V<V<int>>(n+1, V<int>(k+1, 0)));
    F(i,n+1) F(j,n+1) F(kk,k+1) {
        if (j < n) MA(lcs[i][j+1][kk], lcs[i][j][kk]);
        if (i < n) MA(lcs[i+1][j][kk], lcs[i][j][kk]);
        if (kk < k) MA(lcs[i][j][kk+1], lcs[i][j][kk]);
        if (i < n && j < n) {
            if (s[i] == t[j])
                MA(lcs[i+1][j+1][kk], lcs[i][j][kk] + 1);
            else if (kk < k)
                MA(lcs[i+1][j+1][kk+1], lcs[i][j][kk] + 1);
        }
    }
    int ma=0;
    F(i,n+1) {
        // without center
        MA(ma, 2*lcs[i][n-i][k]);
        if (i<n) {
            MA(ma, 2*lcs[i][n-1-i][k] + 1);
        }
    }
    cout << ma << "\n";
}