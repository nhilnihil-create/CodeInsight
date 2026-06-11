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
 
const int maxx=1e6+9;
 
// Happy Coding!



void solve(){
    
    ll n,m;
    cin>>n>>m;
    
    vector<pll> arr;
    for(ll i=0;i<n;i++){
        ll p,c;
        cin>>p>>c;
        arr.push_back({p,c});
    }
    sort(all(arr));
    ll cans=m;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll p=arr[i].Fi;
        ll c=arr[i].Se;
        if(cans>c){
            cans-=c;
            ans+=c*p;
        }
        else{
            ans+=cans*p;
            cans=0;
            break;
        }
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