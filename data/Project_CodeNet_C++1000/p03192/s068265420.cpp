#include<bits/stdc++.h>
using namespace std;
int temp[1000];
int main()
{
  int n;
  cin>>n; 
  vector<int>v;
  
  int c=0;
  while(n!=0)
  {
    int r=n%10;
    n/=10;
    v.push_back(r);
    c++;
  }
  
  int ok=0;
  for(auto x:v)
     if(x==2)
        ok++;
    cout<<ok<<"\n";    
  
  //int mx=0;
  
  
  //for(int i=0;i<c;i++){
    //temp[i]=temp[v[i]]++;
    //mx=max(mx,temp[i]);
    //cout<<temp[i];
  //}
  //if(mx>=1)
    //cout<<mx<<"\n";
    //else cout<<"0"<<"\n";
}