#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string n;

int main(){
  cin >> n;
  rep(i, n.size()){
    if (n[i]=='1') n[i]='9';
    else n[i]='1';
  }
  cout << n << endl;
}
