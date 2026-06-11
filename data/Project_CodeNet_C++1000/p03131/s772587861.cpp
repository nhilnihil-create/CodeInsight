//#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
  ll k,a,b; cin >>k>>a>>b;
  if(b<=a+2){
    cout<<k+1<<endl;
    return 0;
  }
  ll sum=0;
  if((k-a)%2==0)sum=(k-a)/2*(b-a)+a+1;
  if((k-a)%2==1)sum=(k-a+1)/2*(b-a)+a;
  cout<<sum<<endl;
}