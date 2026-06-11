#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n,a,b;
  cin>>n;
  cin>>a>>b;
  int p[n];
  for(i=0;i<n;i++)cin>>p[i];
  int p1=0,p2=0,p3=0;
  for(i=0;i<n;i++){
    if(p[i]<=a)p1++;
    else if(a<p[i] && p[i]<=b)p2++;
    else p3++;
  }
  cout<<min(p1,min(p2,p3));
}