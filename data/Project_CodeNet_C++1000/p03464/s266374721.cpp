#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[100010];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll mi=2,ma=2;
	for(ll i=n-1;i>=0;i--){
		mi=(mi+a[i]-1)/a[i]*a[i];
		ma=(ma/a[i]+1)*a[i]-1;
		if(mi>ma){
			cout <<-1<<endl;
			return 0;
		}
		//cout << mi<<" "<<ma<<endl;
	}
	cout << mi<<" "<<ma;
	// your code goes here
	return 0;
}