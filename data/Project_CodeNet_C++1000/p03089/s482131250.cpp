#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>a,ans;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		a.push_back(now);
	}
	while(a.size()){
		bool ch=false;
		for(ll i=a.size()-1;i>=0;i--){
		//	cout << "K"<<endl;
			if(a[i]==i+1){
				ans.push_back(a[i]);
				a.erase(a.begin()+i);
				ch=true;
				break;
			}
		}
		if(ch==false){
			cout << -1;
			return 0;
		}
	}
	reverse(ans.begin(),ans.end());
	for(ll i=0;i<n;i++){
		cout << ans[i]<<endl;
	}
	// your code goes here
	return 0;
}