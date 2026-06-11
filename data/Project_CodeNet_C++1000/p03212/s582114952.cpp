#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


vector<int> num;
int a[3] = {3,5,7};
void f(int x) {
  vector<int> aa = {0}, bb;
  bool ok = true;
  while(ok) {
    for(auto p : aa) {
      rep(i,3) {
        int mm = p*10+a[i];
        if(mm>x) {
          ok = false;
          break;
        }
        num.push_back(mm);
        bb.push_back(mm);
      }
    }
    aa = bb;
    bb.erase(rng(bb));
  }
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  f(n);
  for(auto i : num) {
    int m = i;
    int b[10];
    memset(b,0,sizeof(b));
    while(m>0) {
      b[m%10]++;
      m /= 10;
    }
    if(b[3]>0&&b[5]>0&&b[7]>0) ans++;
  }
  cout << ans << endl;
  return 0;
}