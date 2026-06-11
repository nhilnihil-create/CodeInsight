#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<string >blue(n);
  for(int i=0;i<n;i++)cin>>blue[i];
  int m;cin>>m;
  vector<string >red(m);
  for(int i=0;i<m;i++)cin>>red[i];
  int maxi=0;
  for(int i=0;i<n;i++){
  	string s = blue[i];
    int curr=0;
    for(int j=0;j<n;j++)if(blue[j]==s)curr++;
    for(int j=0;j<m;j++)if(red[j]==s)curr--;
    maxi = max(maxi,curr);
  }
  cout<<maxi;
}