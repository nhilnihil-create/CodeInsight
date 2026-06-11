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
    string s[n] = {};
    ll cnt = 0;
    ll a = 0,b = 0,both = 0;
    rep(i,0,n){
        cin >> s[i];
        rep(j,0,s[i].size()-1){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') cnt++;
        }
        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') both++;
        else if(s[i][0] == 'B') b++;
        else if(s[i][s[i].size()-1] == 'A') a++;
    }
    
    if(min(a,b) > 0) cout << cnt + min(a,b) + both << endl;
    else if(a == 0 && b == 0) cout << cnt + max(0LL,both -1) << endl;
    else cout << cnt + both << endl;
     
    return 0;
}
