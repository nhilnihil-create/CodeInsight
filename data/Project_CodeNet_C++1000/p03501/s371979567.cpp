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
  int n,a,b;
  cin >> n >> a >> b;
  cout << min(n*a,b);
  return 0;
}
