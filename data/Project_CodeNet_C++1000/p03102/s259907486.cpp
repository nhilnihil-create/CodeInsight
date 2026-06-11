#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!

void solve(){

    ll n,m,c;
    cin>>n>>m>>c;
    
    vll B(m);
    ll ans=0;
    for(int i=0;i<m;++i){cin>>B[i];}
    
    for(int i=0;i<n;i++){
        ll sum=c;
        for(int j=0;j<m;j++){
            ll aj;
            cin>>aj;
            sum+=(B[j]*aj);
        }
        // cout<<sum<<" ";
        if(sum>0)
          ans++;
    }
    cout<<ans<<endl;
}

 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}