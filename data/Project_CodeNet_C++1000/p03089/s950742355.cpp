#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110];
bool f[110];
int main(){
	ll n;
	vector<ll>ans;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ll cnt=0;
		bool ok=0;
		for(int j=n-1;j>=0;j--){
			if(f[j]){
				cnt++;
				continue;
			}
			if(a[j]==i-cnt){
				ok=1;
				ans.push_back(a[j]);
				f[j]=1;
				break;
			}
		}
		if(!ok){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(auto x:ans){
		cout<<x<<endl;
	}
	return 0;
}
