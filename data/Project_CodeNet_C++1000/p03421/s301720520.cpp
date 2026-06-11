// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
bool solve(ll n, ll a, ll b,vector<ll> &ans){
  if(a+b-1>n||b==0){
    return false;
  }
  if(a+b-1==n){
    for(int i=0;i<a;i++){
      ans.push_back(b+i);
    }
    for(int i=0;i<b-1;i++){
      ans.push_back(b-1-i);
    }
    return true;
  }
  for(int i=0;i<a;i++){
    ans.push_back(n-a+1+i);
  }
  n -= a;
  b--;
  if(n+1-b<=a){
    return solve(n,n+1-b,b,ans);
  }else{
    return solve(n,a,b,ans);
  }
}
signed main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> ans;
  if(solve(n,a,b,ans)){
    for(auto i:ans){
      cout << i<<" ";
    }
    cout << endl;
  }else{
    cout << -1 <<endl;
  }
}
