#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main(){
	int n,x; cin>>n>>x;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	sort(all(v));
	rep(i,n){
		if(x-v[i]>=0) {x-=v[i]; v[i]=0;}
	}
	if(x>0) v[n-1]-=x;
	int cnt=0;
	rep(i,n){
		if(v[i]==0) cnt++;
	}
	cout<<cnt<<endl;
}