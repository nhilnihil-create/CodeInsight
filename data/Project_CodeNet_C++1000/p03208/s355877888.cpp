#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n)
    cin >> a.at(i);
  sort(all(a));
  int c=2000000000;
  rep(i,n-k+1){
    c=min(c,a.at(k+i-1)-a.at(i));
  }
  cout << c << endl;
}