//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 5000 + 5;
const int M = 5e5 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int n,k;
map<int,int> cnt;
ll ans;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        if(i%k==(-i%k + k)%k) cnt[i%k]++;
    }

    for(auto i:cnt) ans += 1LL*i.s*i.s*i.s;

    cout << ans << '\n';

    return 0;
}