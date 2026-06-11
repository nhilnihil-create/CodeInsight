#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  vector<int> V(N, 0);
  int a, ans=0;
  for (int i=0; i<N; i++) {
    cin >> a;
    if (a>N) {ans++;}
    else {
      V[a-1]++;
    }
  }
  for (int i=0; i<N; i++) {
    if (V[i]>i+1) {
      ans+=V[i]-(i+1);
    }
    else if (V[i]<i+1) {
      ans+=V[i];
    }
  }
  cout << ans << endl;
}
 