#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

double a[102];
int main() {
	double n;
	cin>>n;
	double sum=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	ll ans=0;
	double now=abs(sum-a[0]);
	for(ll i=0;i<n;i++){
		if(abs(sum-a[i])<now){
			now=abs(sum-a[i]);
			ans=i;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}