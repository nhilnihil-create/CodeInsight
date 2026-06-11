#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N,H,W;
  cin>>N>>H>>W;
  int cnt(0);
  for(int i(0);i<N;i++){
    int a,b;
    cin>>a>>b;
    if(a >= H && b >= W) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

