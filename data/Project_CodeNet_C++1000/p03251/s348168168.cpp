#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n,m,x,y;
  cin >> n>>m>>x>>y;
  int xma = -1000, ymi = 1000;
  int a;
  rep(i, n){
    cin >> a;
    xma = max(xma, a);
  }
  rep(i, m){
    cin >> a;
    ymi = min(ymi, a);
  }
  if(xma < ymi && x < ymi && ymi <= y) {
    cout << "No War" << endl;
  }
  else cout << "War" << endl;
  return 0;
}