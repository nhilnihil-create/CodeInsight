#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    ld t[N], v[N];
    rep(i, N) cin >> t[i];
    rep(i, N) cin >> v[i];
    //a[i]:=t[i-1]が終わった直後の速度
    ld a[N+1];
    a[0] = a[N] = 0;
    rep2(i, 1, N-1){
        a[i] = min(v[i-1], v[i]);
    }
    while(true){
        bool update = false;
        rep(i, N){
            if(abs(a[i+1]-a[i]) > t[i]){
                if(a[i+1] > a[i]) a[i+1] = a[i]+t[i];
                else a[i] = a[i+1]+t[i];
                update = true;
            }
        }
        if(!update) break;
    }
    ld ans = 0;
    rep(i, N){
        ld x = a[i]-a[i+1], tmp = 0;
        ld t1 = (t[i]-x)/2, t2 = (t[i]+x)/2, Mv = a[i] + t1;
        tmp += (a[i]+Mv)*t1/2 + (a[i+1]+Mv)*t2/2;
        if(Mv > v[i]){
            tmp -= (Mv-v[i])*(Mv-v[i]);
        }
        ans += tmp;
    }
    cout << sp(10) << ans << endl;
}