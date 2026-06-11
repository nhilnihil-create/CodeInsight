#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  int q1 = 0,q2 = 0,q3 = 0;
  rep(i,0,n){
    int p;
    cin >> p;
    if(p <= a) q1++;
    else if(p <= b) q2++;
    else q3++;
  }
  int m = min(q1,q2);
  m = min(m,q3);
  cout << m << endl;
}