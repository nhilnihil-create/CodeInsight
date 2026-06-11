#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(s) (int)s.size()
#define y1 fdfbvfds
typedef long double f80;
#define all(x) x.begin(), x.end()
typedef long double f80;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l,ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}
 
const int mod = 998244353;
int pwr(int a,int b) {
    int ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}

const int NN = 4e6 + 5;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bitset<NN> b;
    int sum = 0;
    b[0] = 1;
    fr(i, 1, n) {
        int x;
        cin >> x;
        sum += x;
        b |= (b << x);
    }
    fr(i, (sum + 1) / 2, NN - 1) {
        if(b[i]) {
            cout << i;
            return 0;
        }
    }
    return 0;
}