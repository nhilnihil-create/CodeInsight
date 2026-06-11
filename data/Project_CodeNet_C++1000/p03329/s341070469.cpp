#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> vec;
  int six = 6;
  while(six <= 100000){
    vec.push_back(six);
    six *= 6;
  }
  int nine = 9;
  while(nine <= 100000){
    vec.push_back(nine);
    nine *= 9;
  }
  vec.push_back(1);
  sort(all(vec));
  vector<int> dp(100001);
  dp[0] = 0;
  for(int i=1; i<=100000; i++){
    int smallest = 1000000000;
    rep(j, vec.size()){
      if(vec[j]<=i) smallest = min(smallest, dp[i-vec[j]]+1);
    }
    dp[i] = smallest;
  }
  cout << dp[n] << endl;
  return 0;
}
  