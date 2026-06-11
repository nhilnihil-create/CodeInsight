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
  
  string s;
  cin>>s;
  int i,j;
  vector<int> v;
  int count;
  for(i=0;i<s.length();i++){
  	count=0;
  	if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T')
  	{ 
  	  count++;
  	  for(j=i+1;j<s.length();j++){
  	  	if(s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T'){
  	  		  count++;
			}
		 else{
		 	v.push_back(count);
		 	break;
		 }
		 	
		}
		 
		if(j==s.length()){
			v.push_back(count);
		} 
	    	
	  }
  }
  
  if(v.size()==0){
  	cout<<"0"<<endl;
  }
  else{
  	cout<<*max_element(v.begin(),v.end())<<endl;
  }
  
  
  return 0;
}