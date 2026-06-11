#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1 << 30;


int main()
{
    int n;
    cin >> n;
    vector<int> t(n),v(n);
    vector<int> st(n+1,0);
    rep(i,n) {
        cin >> t[i]; t[i] *= 2;
        st[i+1] = st[i] + t[i];
    }
    rep(i,n) {
        cin >> v[i]; v[i] *= 2;
    }

    int T = st[n];//終着時刻
    vector<int> lim(T+1,INF);
    lim[0] = 0, lim[T] = 0;
    rep(i,n) {
        for(int j = st[i]; j <= st[i+1]; ++j) {
            chmin(lim[j],v[i]);
        }
    }

    for(int i = T; i > 0; --i) {
        chmin(lim[i-1],lim[i]+1);
    }

    //条件はact[i] <= lim[i]のみ
    vector<int> act(T+1,0);
    for(int i = 0; i < T; ++i) {
        act[i+1] = min(act[i]+1, lim[i+1]);
    }

    ll res = 0;
    for(int i = 1; i < T; ++i) {
        res += 2*act[i];
    }
    cout << fixed << setprecision(10) << (double)res/(4*2) << endl;
    return 0;
}