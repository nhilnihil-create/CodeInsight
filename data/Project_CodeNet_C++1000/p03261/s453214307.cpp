#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 


string w[110];

int solve() {
  int n;
  cin >> n;

  for (int i=0; i< n; ++i) {
    cin >> w[i];
  }
//bool値をだして、w[i]の中の末尾と頭を比較
  bool ans =true;
  for (int i=0; i< n-1;++i) {
    if (w[i][w[i].size()-1] != w[i+1][0]){
      ans = false;

    }
  }

  for (int i=0;i<n;i++) {
    for (int j=0;j<i;j++) {
      if(w[i] == w[j]) {
        ans = false;
      }
    }
  }

  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}


int main(){
  solve();
  return 0;
}
