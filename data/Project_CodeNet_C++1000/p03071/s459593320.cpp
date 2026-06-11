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
  
  int a,b;
  cin>>a>>b;
  int s=0;
  if(a>=b){
  	s=s+a;
  	a--;
  	if(a>=b){
  		s=s+a;
  		a--;
	}
	else if(b>=a){
		s=s+b;
		b--;
	}
	
  }
  
  else if(b>=a){
  	s=s+b;
  	b--;
  	if(b>=a){
  		s=s+b;
  		b--;
	}
	else if(a>=b){
		s=s+a;
		a--;
	}
  }
  
  cout<<s<<endl;

  return 0;
}