#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int main(){
  int n;
  cin >> n;
  string ans = "";
  if (n == 0) ans = "0";
  while(n != 0){
    if (n % 2 != 0){
      n--;
      ans = '1' + ans;
    }
    else ans = '0' + ans;
    n /= -2;
  }
  cout << ans << endl;
}

