#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	int cnt=0;
	for(int i=1; i<n-1; i++){
		if(v[i-1]==v[i]&&v[i]==v[i+1]) {cnt++; v[i]=0;}
	}
	for(int i=0; i<n-1; i++){
		if(v[i]==v[i+1]) {cnt++; v[i]=-1;}
	}
  cout<<cnt<<endl;
}