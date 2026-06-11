//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int OO = 2e9;
const int mod = 1e9+7;

void init() {

}

int n;
ll m,a[N],cum[N],cur,ans;
map<int,int> x,y;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;++i) {

        cin >> a[i];
        a[i] %= m;
        if(i) cum[i] = cum[i-1];
        cum[i] = (cum[i]+a[i])%m;
        x[cum[i]]++;

    }

    for(int i=0;i<n;++i) {

        ans += x[cur]-y[cur];
        y[cum[i]]++;
        cur = (cur+a[i]+m)%m;
    }

    cout << ans << '\n';

    return 0;

}