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
  
  int a,b,c;
  cin>>a>>b>>c;
  if(c>a&&c>b||c<a&&c<b){
  	cout<<"No"<<endl;
  }

  else{
  	cout<<"Yes"<<endl;
  }
  
  return 0;
} 