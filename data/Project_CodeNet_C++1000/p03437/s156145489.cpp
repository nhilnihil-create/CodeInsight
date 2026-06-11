#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int x,y;

int main() {
  cin >> x  >> y;
  if(x==y||y==1||x%y==0)
  cout << -1 << endl;
  else
  cout << x << endl;
}