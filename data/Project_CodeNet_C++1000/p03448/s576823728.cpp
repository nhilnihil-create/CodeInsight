#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.14159265358979;


int main(){
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  a++;b++;c++;
  x /= 50;
  //10a + 2b+c = x
  int ans = 0;
  rep(i, a){
    rep(j, b){
      rep(k, c){
        if(10*i + 2*j + k == x) ans++;
      }
    }
  }
  cout << ans <<endl;
  
  
}