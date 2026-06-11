#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  ll m;
  cin >> m;
  if(n == 1){
    cout << m << endl;
    return 0;
  }
  ll b = 2;
  vector<ll> d;
  while(m >= b * b) {
    if(m % b == 0) {
      d.push_back(b);
      d.push_back(m / b);
    }
    b++;
  }
  ll maxi = 1;
  for(int i = 0; i < d.size(); i++){
    if((m - d[i] * n) >= 0 && (m - d[i] * n) % d[i] == 0) {
      maxi = max(maxi, d[i]);
    }
  }
  cout << maxi << endl;
  return 0;
}