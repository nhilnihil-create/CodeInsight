#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 
ll a[200010];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0,cnt=0;
	for(ll i=0;i<n;i++){
		if(a[i]>cnt){
			cout << -1;
			return 0;
		}
		else{
			if(a[i]==cnt){
				if(cnt!=0){
					ans++;
				}
				cnt++;
			}
			else{
				ans+=a[i];
				cnt=a[i]+1;
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}