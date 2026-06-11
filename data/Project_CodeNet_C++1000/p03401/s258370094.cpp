#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	ll sum=0;
	vector<int> v(n+2);
	vector<int> d(n+1);
	for(int i=1; i<n+2; i++){
		cin>>v[i];
		d[i-1]=abs(v[i-1]-v[i]);
		sum+=d[i-1];
	}
	for(int i=1; i<n+1; i++){
		cout<<sum-(d[i-1]+d[i])+abs(v[i-1]-v[i+1])<<endl;
	}
}