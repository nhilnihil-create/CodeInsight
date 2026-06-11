#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans = 0;
    int r = 0;
    ll sum = 0;
    rep(l, N)
    {
        while(r < N && (sum + a[r]) == (sum ^ a[r]))
        {
            sum += a[r++];
        } 
        ans += r-l;
        if(l == r) r++;
        else sum -= a[l];
    }
    cout << ans << endl;
    return 0;
}