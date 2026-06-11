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

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll p[n] = {};
    ll cnt[3] = {};
    rep(i,0,n){
        cin >> p[i];
        if(p[i] <= a) cnt[0]++;
        else if(p[i] <= b) cnt[1]++;
        else cnt[2]++;
    }

    cout << min(cnt[0],min(cnt[1],cnt[2])) << endl;
    return 0;
}
