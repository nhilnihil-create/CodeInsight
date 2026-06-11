#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long 
#define dd double
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b;
  cin>>a>>b;
  if(a>=13){
  	cout<<b<<endl;
  }
  else if(a>=6&&a<=12){
  	cout<<b/2<<endl;
  }
  else if(a<=5){
  	cout<<"0"<<endl;
  }
  
  
  return 0;
}