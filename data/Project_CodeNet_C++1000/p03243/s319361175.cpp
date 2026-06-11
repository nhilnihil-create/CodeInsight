#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1e18;

int main(){
  int n;
  cin >> n;

  vector<int> aaa;
  int b = 0;
  rep(i,9){
    b += 111;
    aaa.push_back(b);
  }

  for(int i : aaa){
    if(n<=i){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}