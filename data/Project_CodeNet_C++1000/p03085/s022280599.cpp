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
  
  char ch;
  cin>>ch;
  if(ch=='A'){
  	cout<<"T"<<endl;
  }
  else if(ch=='T'){
  	cout<<"A"<<endl;
  }
  else if(ch=='C'){
  	cout<<"G"<<endl;
  }
  else if(ch=='G'){
  	cout<<"C"<<endl;
  }
  
  return 0;
}