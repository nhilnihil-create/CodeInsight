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
signed main(){
  string s;
  ll w,n;
  cin >> s >> w;
  n = s.size();
  for(int i=0;i<n;i++){
    if(i%w==0) cout << s[i];
  }
  cout << endl;
}
