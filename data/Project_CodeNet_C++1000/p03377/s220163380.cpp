#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int a, b, x;
  cin >> a >> b >> x;
  if(a<=x && x<=a+b) cout << "YES" <<endl;
  else cout << "NO"<<endl;
}