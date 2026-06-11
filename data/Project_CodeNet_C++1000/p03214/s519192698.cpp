#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

double a[102];
int main() {
	ll n;
	cin>>n;
	double hei=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		hei+=a[i];
	}
	hei/=n;
	double ch=inf;
	ll ans=0;
	for(ll i=0;i<n;i++){
		double now=abs(a[i]-hei);
		if(now<ch){
			ch=now;
			ans=i;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}