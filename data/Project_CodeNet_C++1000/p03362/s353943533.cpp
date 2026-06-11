// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
vector<ll> eratos(int max){
  vector<ll> res;
  vector<bool> cp_list(max+1,true);
  cp_list[0]=false;
  cp_list[1]=false;
  for(ll i=2;i<=max;i++){
    if(cp_list[i]){
      res.push_back(i);
      for(ll j=2;j*i<=max;j++){
        cp_list[i*j]=false;
      }
    }
  }
  return res;
}
signed main(){
  init_io();
  ll n;
  vector<ll> plist = eratos(55555);
  cin >> n;
  for(auto p:plist){
    if(p%5==1){
      cout << p;
      n--;
      if(n!=0) cout <<" ";
      else{
        cout << endl;
        break;
      }
    }
  }
}
