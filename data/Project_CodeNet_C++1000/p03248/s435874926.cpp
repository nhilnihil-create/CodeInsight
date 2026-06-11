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
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  ll n,n_use=1;
  string s;
  cin >> s;
  n = s.size();
  ll v = n-1;
  if(s.front()=='0'||s.back()=='1'){
    cout <<-1<<endl;
    return 0;
  }
  for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-2-i]){
      cout << -1<<endl;
      return 0;
    }
  }
  s[n-1] = '1';
  for(int i=n-2;i>=0;i--){
    cout << v+1 <<" "<<i+1<<endl;
    if(s[i]=='1'){
      v = i;
    }
  }
}
