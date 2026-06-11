#include <bits/stdc++.h>
using namespace std;
#define dbg(x) #x "=" << x << " "
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    fore(i,1,n+1) {
        int m = i%k;
        if (m == (-m+k)%k) {
            cnt[m]++;
        }
    }
    ll ans = 0;
    for (auto &x : cnt) {
        ans += 1ll*x.S*x.S*x.S;
    }
    cout << ans << endl;
}
