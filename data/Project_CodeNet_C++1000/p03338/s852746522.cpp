#define _GLIBCXX_DEBUG
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
  ll n; cin >>n;
  string s; cin >>s;
  int ans=0;
  rep(i,n){
    int count=0;
    for(char a='a';a<='z';a++){
      int key1=0;
      int key2=0;
      rep(j,i+1){
        if(s[j]==a){
          key1=1;
          break;
        }
      }
      rep2(j,i+1,n){
        if(s[j]==a){
          key2=1;
          break;
        }
      }
      if((key1==1)&&(key2==1)) count++;
    }
    ans=max(ans,count);
  }
  cout <<ans<<endl;
}
      
      
      