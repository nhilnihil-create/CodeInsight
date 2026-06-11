#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int n,k;
  cin >> n >> k;
  
  
  if((n-1)%(k-1)==0){
    cout << (n-1)/(k-1) << endl;
  }
  else{
    cout << (n-1)/(k-1)+1 << endl;
  }
  
}