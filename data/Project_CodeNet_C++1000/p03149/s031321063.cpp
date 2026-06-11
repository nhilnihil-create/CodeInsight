#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  vector<int> a(4);
  rep(i,4) cin >> a[i];
  sort(a.begin(), a.end());
  if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
} 