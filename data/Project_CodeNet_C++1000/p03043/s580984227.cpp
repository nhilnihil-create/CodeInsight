#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
const ll MOD = 1e9 + 7; 
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(12);
  double n,k;
  cin>>n>>k;
  int i;
  double ans;
  double s=0;
  for(i=1;i<=n;i++){
  double j=i;
  double p=2;
  ans=1;
  while(j<k){
  	j=j*2;
  	ans=ans*1/p;	
  }
  
  ans=ans*1/n;
  s=s+ans;
   
 }

  cout<<s<<endl;
  
  return 0;
}