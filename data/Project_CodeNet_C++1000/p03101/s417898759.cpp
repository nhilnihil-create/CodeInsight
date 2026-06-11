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
  
  int H,W;
  cin>>H>>W;
  int h,w;
  cin>>h>>w;
  int a=abs(H-h);
  int b=abs(W-w);
  cout<<a*b<<endl;
  
  return 0;
}