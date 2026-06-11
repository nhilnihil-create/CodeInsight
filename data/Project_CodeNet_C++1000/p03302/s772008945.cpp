#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,m,a,b,c,d;
string s;

int main() {
  cin >> a >> b;
  if(a+b==15)
  cout << '+' << endl;
  else if(a*b==15)
  cout << '*' << endl;
  else 
  cout << 'x' << endl;
}