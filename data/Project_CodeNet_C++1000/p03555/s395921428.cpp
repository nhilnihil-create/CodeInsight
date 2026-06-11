#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  string a, b;
  cin >> a >> b;
  reverse(all(b));
  if(a == b) cout << "YES" <<endl;
  else cout << "NO" <<endl;
}