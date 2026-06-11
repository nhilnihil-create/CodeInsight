#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
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


//素因数分解し、mapに<素数、個数>で格納
map<ll,ll> primes(ll n){
    map<ll, ll> r;
    for(int i=2; i*i<=n; i++){ 
        while(n % i ==0){
            r[i]++;
            n /= i;
        }
    }

    if(n != 1) r[n] = 1;
    return r;
}

int main(){FIN

    ll n; cin>>n;
    ll ans=0;
    vll a(n); REP(i,n) {
        cin>>a[i];
        while(a[i]%2==0){
            a[i] /= 2;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}