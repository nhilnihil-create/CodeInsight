#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  string N;
  cin>>N;
  int cnt(0);
  for(int i(0);i<4;i++){
    if(N[i] == '2') cnt++;
  }
  cout << cnt << endl;
  return 0;
}

