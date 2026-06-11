#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = vector<T>;
using vvi = vector<vector<int>>;

void svtr(vector<int> &a){
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
}

int main() {
  int H,W,h,w;
  cin >> H >> W >> h >> w;

  cout << (H-h)*(W-w) ;
  return 0;
}
