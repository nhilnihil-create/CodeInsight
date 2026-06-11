#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
  vector<int >iis(k,0);
  for(int i=0;i<n;i++){
  	int l;cin>>l;
    for(int j=0,a;j<l;j++){
    	cin>>a;iis[a-1]++;
    }
  }
  int tot=0;
  for(int i=0;i<k;i++)if(iis[i]==n)tot++;
  cout<<tot;
}