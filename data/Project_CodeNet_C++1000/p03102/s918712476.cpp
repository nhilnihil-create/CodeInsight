#include<bits/stdc++.h>
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 	pb	push_back 
#define 	ff	first 
#define 	ss	second 
#define sz(x) (int)x.size()
#warning Remeber to change t
using namespace std;
typedef long long ll;
inline void setIO(string name="") {
	#ifndef ONLINE_JUDGE 
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
	#endif
	}

int main(){
	Speed_UP
	ll t;
	t=1;
	while(t--){
		ll n,m,c;
		cin>>n>>m>>c;
		ll arr[m];
		for(int i=0;i<m;i++)
			cin>>arr[i];
		ll co=0;
		for(int i=0;i<n;i++){
				ll ans=c;
				for(int j=0;j<m;j++){
					ll a;
					cin>>a;
					ans+=a*arr[j];
				}
				if(ans>0)
					co++;
		}
		cout<<co;
		
		
		
	}





}
