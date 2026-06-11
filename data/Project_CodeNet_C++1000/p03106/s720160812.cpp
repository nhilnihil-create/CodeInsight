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
  
  int a,b,k;
  cin>>a>>b>>k;
  vector<int> v;
  int n=max(a,b);
  int i;
  for(i=1;i<=n;i++){
  	if(a%i==0&&b%i==0){
  		v.push_back(i);
	  }
  }
  
  sort(v.begin(),v.end(),greater<int>());
  cout<<v[k-1]<<endl;
  
  return 0;
}