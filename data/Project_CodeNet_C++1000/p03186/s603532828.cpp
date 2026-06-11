#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b,c;  
string s;

int main() {
  cin >> a >> b >> c;
  if(a+b>=c)
  cout << b+c << endl;
  else 
  cout << a+b+b+1 << endl;
}