#include <bits/stdc++.h>

#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(long long i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(long long i = m; i <= n; i++)
#define FORR(i, m, n) for(long long i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;

map<ll,ll> r;

void primes(ll n){
    
    for(int i=2; i<=n; i++){
        while(n % i ==0){
            r[i]++;
            n /= i;
        }
    }

    if(n != 1) r[n] = 1;
    // return r;
}

int main(){FIN

    ll n;cin>>n;
    FOR(i,1,n) primes(i);
    map<ll,ll> num;
    for(auto p: r){
        // cout<<p.first<<' '<<p.second<<endl;
        if (p.second>=2) num[2]++;
        if (p.second>=4) num[4]++;
        if (p.second>=14) num[14]++;
        if (p.second>=24) num[24]++;
        if (p.second>=74) num[74]++;
    }
    ll ans=0;
    ans += num[4] * (num[4]-1) / 2 * (num[2]-2);
    ans += num[14] * (num[4]-1);
    ans += num[24] * (num[2]-1);
    ans += num[74];
    cout<<ans<<endl;
    return 0;
}