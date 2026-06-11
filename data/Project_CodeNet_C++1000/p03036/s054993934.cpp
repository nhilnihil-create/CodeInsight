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
  int r,d,x;
  cin>>r>>d>>x;
  int t=10;
  int x1;
  while(t--){
  	x1=(r*x)-d;
  	cout<<x1<<endl;
  	x=x1;
  }
  
  return 0;
}