#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;cin>>n>>q;
  string s;
  cin>>s;
  vector<int >nos(n,0);
  for(int i=1;i<n;i++){
  	if(s[i]=='C' && s[i-1]=='A')nos[i]=nos[i-1]+1;
    else nos[i]=nos[i-1];
  }
  for(int i=0,a,b;i<q;i++){
    cin>>a>>b;
  	cout<<nos[b-1]-nos[a-1]<<'\n';
  }
}