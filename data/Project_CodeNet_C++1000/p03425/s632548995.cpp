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
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second


int main(){
    ll n;
    cin >> n;
    string s[n];
    char memo[5] = {'M','A','R','C','H'};
    ll cnt[5] = {};

    rep(i,0,n){
        cin >> s[i];
        rep(j,0,5){
            if(s[i][0] == memo[j]){
                cnt[j]++;
            }
        }
    }

    ll ans = 0;
    rep(i1,0,5){
        rep(i2,i1+1,5){
            rep(i3,i2+1,5){
                ans += cnt[i1]*cnt[i2]*cnt[i3];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
