#include<stdio.h>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n; cin>>n;
  // vector<int> a(n);
  // rep(i,n){
  //   cin>>a[i];
  // }
  string ans="No";
  rep(i,n){
    rep(j,n){
      if(4*i+7*j==n){
        ans="Yes";
        goto fin;
      }
    }
  }
  fin:
  cout<<ans;

  // cout<<a[0];
    
  
  
  return 0;
}