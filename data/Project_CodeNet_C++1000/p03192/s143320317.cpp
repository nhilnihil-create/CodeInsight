#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

ll n,k,m,a,b;
string s;

int main() {
  cin >> s;
  int ans=0;
  for(auto c:s)if(c=='2') ans++;
  cout << ans << endl;
}