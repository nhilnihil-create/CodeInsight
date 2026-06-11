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
    ll t;
    cin>>t;
    vector<int> v;
    while(t--){
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;
    	if(a<b||d<b){
    		v.pb(0);
    		continue;
    	}
    	ll g=__gcd(d,b);
    	if((c+g-a%g)/g*g+a%g<b){
    		v.pb(0);
    	}else{
    		v.pb(1);
    	}
    }
    for(auto& i:v)cout << ((i)?"Yes":"No") <<endl;
    return 0;
}
