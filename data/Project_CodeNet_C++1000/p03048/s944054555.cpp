#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int R, G, B, n;
  cin >> R >> G >> B >> n;
  int cnt = 0;
  for(int i=0; n-R*i>=0; i++) {
    for(int j = 0; n-R*i-G*j>=0; j++) {
      if((n-R*i-G*j)%B==0) cnt++;
    }
  }

  cout << cnt << endl;
}
