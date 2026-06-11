#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(abs(c-a)<=d || (abs(a-b)<=d&&abs(c-b)<=d)) cout << "Yes" <<endl;
  else cout << "No" <<endl;
}