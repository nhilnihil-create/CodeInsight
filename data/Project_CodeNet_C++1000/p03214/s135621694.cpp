#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

double a[102];
int main() {
	double n,sum=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	double p=sum/n;
	double sa=abs(p-a[0]);
	ll ans=0;
	for(ll i=1;i<n;i++){
		double now=abs(p-a[i]);
		if(now<sa){
			ans=i;
			sa=now;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}