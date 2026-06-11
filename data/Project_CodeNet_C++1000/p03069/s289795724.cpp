#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=200001,w[200005]={};
	int b[200005]={};
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='#'){
			b[i]++;
		}
		else{
			w[i]++;
		}
		b[i]+=b[i-1];
		w[i]+=w[i-1];
	}

	for(int i=0;i<n;i++){
		ans=min(ans,b[i-1]+w[n-1]-w[i]);
	}
	cout<<ans<<endl;
  return(0);
}