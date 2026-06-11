#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

ll memo[101];

void prime_factorization(ll n){
    ll temp = n;
    for(ll i = 2; i <= n;i++){
        while(temp % i == 0){
            memo[i]++;
            temp /= i;
        }
    }
    return;
}

int main(){
    ll n,ans = 0;
    ll cnt[501] = {};
    cin >> n;
    rep(i,2,n+1) prime_factorization(i);
    rep(i,1,101) cnt[memo[i]]++;
    rrep(i,0,500) cnt[i] += cnt[i+1];

    if(cnt[74] >= 1) ans += cnt[74];
    if(cnt[2] >= 3 && cnt[4] >= 2) ans += (cnt[2]-2)*(cnt[4]-1)*cnt[4]/2;
    if(cnt[4] >= 2 && cnt[14] >= 1) ans += (cnt[4]-1)*cnt[14];
    if(cnt[2] >= 2 && cnt[24] >= 1) ans += (cnt[2]-1)*cnt[24];

    cout << ans << endl;
    return 0;
}


