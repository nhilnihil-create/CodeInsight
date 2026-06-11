#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  ll x,y;
  cin>>x>>y;
  if(x%y == 0){
    cout << -1 << endl;
  }else{
    cout << x << endl; 
  }
  return 0;
}

