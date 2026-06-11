#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

set<int> X;
int s;
int m = 1;

int main(){
  cin >> s;
  X.insert(s);
  while (true){
    m ++;
    if (s % 2 == 0) s /= 2;
    else s = s*3 + 1;
    if (X.count(s)) break;
    X.insert(s);
  }
  cout << m << endl;
}
