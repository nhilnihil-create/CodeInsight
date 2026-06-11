#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a,b,c;
string s,t;

int main() {
  cin >> a >> b >> c;
  bool ok=a+b+c-max({a,b,c})-min({a,b,c})==c;
  if(ok)
  cout << "Yes" << endl;
  else 
  cout << "No" << endl;
}