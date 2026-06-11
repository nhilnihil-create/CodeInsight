#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
  cin>>n>>x;
  vector<int >sweet(n,0);
  for(int i=0;i<n;i++)cin>>sweet[i];
  sort(sweet.begin(),sweet.end());
  int tot=0;
  for(int i=0;i<n;i++){
  	if(x>=sweet[i]){tot+=1;x-=sweet[i];}
  }
  if(x==0)cout<<min(tot,n);
  else if(x!=0 && tot==n)cout<<n-1;
  else cout<<tot;
}