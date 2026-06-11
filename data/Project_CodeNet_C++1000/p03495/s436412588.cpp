#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  ll n, k;
  cin >> n >> k;
  
  map<ll, ll> ma;
  
  for(int i=0; i<n; i++){
    int a; cin >> a;
    ma[a]++;
  }
  
  int res = 0;
  
  vector<ll> b;
  for(auto it:ma){
    b.push_back(it.second);
  }
  
  sort(b.begin(), b.end());
  int index=0;
  for(int i=k; i<ma.size(); i++){
    res += b[index];
    index++;
  
  }
  
  cout << res << endl;

  return 0;
}