#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a[10];
string s,t;

int main() {
  cin >> s;
  if(s.size()==3) reverse(all(s));
  cout << s << endl;
}