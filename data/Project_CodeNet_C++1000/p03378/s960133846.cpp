#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m,x; cin>>n>>m>>x;
	vector<int> v(n+1);
	rep(i,m){
		int a; cin>>a;
		v[a]++;
	}
	int t0=0;
	for(int i=x; i>=0; i--) t0+=v[i];
	int tn=0;
	for(int i=x; i<n+1; i++) tn+=v[i];
	cout<<min(t0,tn)<<endl;
}