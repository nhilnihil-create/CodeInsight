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
    ll x[n],y[n];
    bool maki=false;
    for(int i=0;i<n;i++){
    	cin>>x[i]>>y[i];
    	if(i)if(((x[i]+y[i])&1)!=((x[i-1]+y[i-1])&1))maki=true;
    }
    if(maki){
    	cout <<-1 <<endl;
    	return 0;
    }
    vector<ll> d;
    for(int i=30;i>=0;i--){
    	d.pb(1LL<<i);
    }
    if(((x[0]+y[0])&1)==0)d.pb(1);
    cout<<d.size()<<endl;
    for(auto& i:d)cout << i <<" ";
    cout <<endl;
    for(int i=0;i<n;i++){
    	ll a=0,b=0;
    	for(auto& j:d){
    		if(abs(a-x[i])>=abs(b-y[i])){
    			if(a>=x[i])a-=j,cout<<"L";
    			else a+=j,cout<<"R";
    		}else{
    			if(b>=y[i])b-=j,cout<<"D";
    			else b+=j,cout << "U";
    		}
    	}
    	cout << endl;
    }
    return 0;
}
