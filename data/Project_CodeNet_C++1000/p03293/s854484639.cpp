#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string a,b;
  cin >> a >> b;
  int x=a.length();
  string c= a+a;
  rep(i,x){
    if(b==c.substr(i,x)){
      cout << "Yes" << endl;
      break;
    }
    if(i==x-1) cout << "No" << endl;
  }
}