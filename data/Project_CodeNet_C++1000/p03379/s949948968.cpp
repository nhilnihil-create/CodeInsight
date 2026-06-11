#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int a[n], b[n];
  rep(i, n){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  rep(i, n){
    int x;
    x = b[n / 2];
    if(x <= a[i]) x = b[n / 2 - 1];
    cout << x << endl;
  }

  return 0;
}