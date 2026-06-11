#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+10);
  rep(i,n) cin >> a[i];
  int count = 0;
  rep(i,n-1){
    if(a[i] == a[i+1]){
      ++count;
      a[i+1] = 101;
    }
  }
  cout << count << endl;
  return 0;
}
