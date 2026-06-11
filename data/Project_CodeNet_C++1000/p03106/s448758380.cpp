#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rall(x) (x).rbegin(),(x).rend()

int main(){
	int a,b,k; cin>>a>>b>>k;
	vector<int> v;
	int mx=max(a,b);
	for(int i=1; i<=mx; i++){
		if(a%i==0&&b%i==0) v.push_back(i);
	}
	sort(rall(v));
	cout<<v[k-1]<<endl;
}