#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b,k;  
string s,t;

int main() {
  cin >> n >> a >> b;
  cout << min(a,b) << " " << max(a+b-n,0) << endl;
}