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
  int n=5;
  int i;
  int a[n];
  for(i=0;i<n;i++){
  	cin>>a[i];
  }
  int b[n];
  for(i=0;i<n;i++){
  	if(a[i]%10!=0){
	  int p=(a[i]/10)*10+10;
	  int s=p-a[i];
	  b[i]=s;	
	  }
	 else{
	 	b[i]=0;
	 } 
	 
  }
  
  
 // for(i=0;i<n;i++){
  //	cout<<a[i]<<" ";
  //}
  
  //cout<<endl;
  //for(i=0;i<n;i++){
  	//cout<<b[i]<<" ";
  //}
  
  //cout<<endl;
  pair<int,int>p[n];
  for(i=0;i<n;i++){
  	p[i]=make_pair(b[i],a[i]);
  }
  
  //for(i=0;i<n;i++){
  	//cout<<p[i].first<<" "<<p[i].second<<endl;
  //}
  
  sort(p,p+n);
  //cout<<endl;
   //for(i=0;i<n;i++){
  	//cout<<p[i].first<<" "<<p[i].second<<endl;
  //}
  
  int s=0;
  for(i=0;i<n-1;i++){
  	s=s+p[i].first+p[i].second;
  	
  }
  
  s=s+p[n-1].second;
  cout<<s<<endl;
  
  
  return 0;
}