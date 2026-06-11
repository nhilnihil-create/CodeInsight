#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b ? a:b;}
ll min(ll a, ll b) {return a<b ? a:b;}


int main(void) {
    ll N;
    cin >> N;
    ll i, j;
    ll a[N+5];
    ll max=-INF, min=INF;
    ll maxid=-1, minid=-1;
    
    for(i=0; i<N; i++) {
        cin >> a[i];
        
        if(max<a[i]) {
            max=a[i];
            maxid=i;
        }
        
        if(min>a[i]) {
            min=a[i];
            minid=i;
        }
        
    }
    
    if(abs(max)>abs(min)) {
        pt(N*2-1);
        
        for(i=0; i<N; i++)
            pt(maxid+1 << " " << i+1);
        
        for(i=1; i<N; i++)
            pt(i-1+1 << " " << i+1);
        
    }else {
        pt(N*2-1);
        
        for(i=0; i<N; i++)
            pt(minid+1 << " " << i+1);
        
        for(i=N-1; i>=1; i--)
            pt(i+1 << " " << i-1+1);
    }
    
}





