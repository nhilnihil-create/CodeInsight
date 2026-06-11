#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int c = 0;

  bool flag = true;
  while(1){
    if(a == 1 && b == 2){
      if(flag){
        cout << "Borys" << endl;
        return 0;
      }
    }

    if(b == n && a == n-1){
      if(!flag){
        cout << "Alice" << endl;
        return 0;
      }
    }

    if(c >= 50000) {
      cout << "Draw" << endl;
      return 0;
    }

    if(flag){
      if(a+1 != b) a++;
      else a--;
    } else {
      if(b-1 != a) b--;
      else b++;
    }
    flag = !flag;
  }

  return 0;
}
