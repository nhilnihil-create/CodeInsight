#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n];
    bool maki=true;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]>i)maki=false;
    	if(i&&a[i]-a[i-1]>=2)maki=false;
    }
    if(!maki){
    	cout << -1<<endl;
    	return 0;
    }
    ll ans=0;
    for(int i=1;i<n;i++){
    	if(a[i]-a[i-1]==1)ans++;
    	else ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
