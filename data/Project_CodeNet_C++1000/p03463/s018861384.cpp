#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b;  
string s;

int main() {
  cin >> n >> a >> b;
  cout << (abs(a-b)&1?"Borys":"Alice") << endl;
}