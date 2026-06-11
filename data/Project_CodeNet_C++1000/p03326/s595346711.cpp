#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

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

int main(){
    ll n,m;
    cin >> n >> m;
    priority_queue<ll,llVEC> pq[8];
    rep(i,0,n){
        ll x[3];
        cin >> x[0] >> x[1] >> x[2];
        rep(j,0,8){
            ll temp = j;
            ll sum = 0;
            rep(k,0,3){
                if((temp >> k) & 1){
                    sum += x[k];
                }
                else{
                    sum -= x[k];
                }
            }
            pq[j].push(sum);
        }
    }

    ll ans = 0;
    rep(i,0,8){
        ll memo = 0;
        rep(j,0,m){
            memo += pq[i].top();
            pq[i].pop();
        }
        ans = max(ans,memo);
    }
    cout << ans << endl;

    return 0;
}