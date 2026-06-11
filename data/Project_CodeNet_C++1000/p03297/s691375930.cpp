#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb(t) push_back(t)
#define pt(num) cout << num << "\n"
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
void chmax(ll a, ll b) {if(a<b) a=b;}
void chmin(ll a, ll b) {if(a>b) a=b;}
ll max(ll a, ll b) {return a>b ? a:b;}
ll min(ll a, ll b) {return a<b ? a:b;}

ll gcd(ll a, ll b) {
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(void) {
    ll N;
    cin >> N;
    
    for(ll _=0; _<N; _++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        
        if(a<b || d<b) {
            pt("No");
        }else if(b-1<=c) {
            pt("Yes");
        }else {
            ll g=gcd(b, d);
            
            ll t=0;
            if(c>a) t=(c-a)/g+1;
            else t=-(a-c-1)/g;
            
            if(a+t*g<b) {
                pt("No");
            }else {
                pt("Yes");
            }
        }
        
    }
    
    
    
    
    
}
