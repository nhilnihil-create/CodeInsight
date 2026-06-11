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
  int a[5];
  int i;
  for(i=0;i<5;i++){
  	cin>>a[i];
  }
  int k;
  cin>>k;
  for(i=0;i<5-1;i++){
  	for(int j=i+1;j<5;j++){
  		if(a[j]-a[i]>k){
  			cout<<":("<<endl;
  			return 0;
		  }
	  }
  }
  
  if(i==4){
  	cout<<"Yay!"<<endl;
  }
  
  return 0;
}