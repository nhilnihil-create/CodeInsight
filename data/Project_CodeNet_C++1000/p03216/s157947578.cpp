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
    string s;
    cin>>n>>s;
    ll q,k;
    cin>>q;
    vector<ll> v;
    while(q--){
    	cin>>k;
    	ll numd=0,numm=0,ans=0,num=0;
    	for(int i=0;i<n;i++){
    		if(i>=k){
    			if(s[i-k]=='D'){
    				num-=numm;
    				numd--;
    			}else if(s[i-k]=='M')numm--;
    		}
    		if(s[i]=='D')numd++;
    		else if(s[i]=='M'){
    			num+=numd;
    			numm++;
    		}else if(s[i]=='C') ans+=num;
    	}
    	v.pb(ans);
    }
    for(auto& i:v)cout << i<<endl;
    return 0;
}
