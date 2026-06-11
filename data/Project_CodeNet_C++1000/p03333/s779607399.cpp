#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int n;
  	cin>>n;
  	vector<int>L(n+1),R(n+1);
  	for(int i=0;i<n;i++)
  		cin>>L[i]>>R[i];
  	sort(L.rbegin(),L.rend());
  	sort(R.begin(),R.end());
  	LL ans=0;
  	for(int i=0;i<=n;i++){
  		//cout<<L[i]<<" "<<R[i]<<endl;
	  	ans+=max(0,L[i]-R[i]);
	}
	cout<<ans*2<<endl;
}