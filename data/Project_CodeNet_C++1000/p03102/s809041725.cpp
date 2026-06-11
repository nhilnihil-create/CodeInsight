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
  int n,m,c;
  cin>>n>>m>>c;
  int b[m];
  int i;
  for(i=0;i<m;i++){
  	cin>>b[i];
  }
  
  int j;
  int a[n][m];
  for(i=0;i<n;i++){
  	for(j=0;j<m;j++){
  		cin>>a[i][j];
	  }
  }
  
  int count=0;
  for(i=0;i<n;i++){
  	int s=0;
  	for(j=0;j<m;j++){
  		s=s+(a[i][j]*b[j]);
	  }
	if(s+c>0){
		count++;
	}
  }
  
  cout<<count<<endl;
  
  return 0;
}