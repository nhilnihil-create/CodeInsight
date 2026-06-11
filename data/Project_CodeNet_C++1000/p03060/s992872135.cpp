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
  
  int n;
  cin>>n;
  int v[n],c[n];
  int i;
  for(i=0;i<n;i++){
  	cin>>v[i];
  }
  for(i=0;i<n;i++){
  	cin>>c[i];
  }
  
  int sum=0;
  int sub=0;
  for(i=0;i<n;i++){
  	if(v[i]>=c[i]){
  		sum=sum+v[i];
  		sub=sub+c[i];
	  }
  }
  
  cout<<sum-sub<<endl;
  
  return 0;
}