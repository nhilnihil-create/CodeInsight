#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  vector<int> c(3,0);
  rep(i,n) {
    int p;
    cin >> p;
    if(p <= a) c[0]++;
    else if(a+1 <= p && p <= b) c[1]++;
    else c[2]++;
  }
  cout << min(c[0],min(c[1],c[2])) << endl;
  return 0;
}