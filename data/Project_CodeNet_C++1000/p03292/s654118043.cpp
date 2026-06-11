#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int a1,a2,a3;cin>>a1>>a2>>a3;
  cout << abs(a1-a2)+abs(a2-a3)+abs(a1-a3)-max(max(abs(a1-a2),abs(a1-a3)),abs(a2-a3)) << endl;
}
