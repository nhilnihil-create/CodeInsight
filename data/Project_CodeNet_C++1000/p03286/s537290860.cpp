#include<stdio.h>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int main(){
  ll n; cin>>n;
  vector<ll> ans;
  if(n==0){
    cout<<0;
    return 0;
  }
  while(n!=0){
    // cout<<n<<endl;
    int r = abs(n)%2;
    ans.push_back(r);
    n-=r;
    n/=-2;
  }
  reverse(ans.begin(),ans.end());
  rep(i,ans.size()) cout<<ans[i];

    
  
  
  return 0;
}