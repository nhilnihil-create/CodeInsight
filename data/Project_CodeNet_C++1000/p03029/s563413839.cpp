#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using p=pair<int,int>;
using V=vector<vector<int>>;

int A, P;

int main(){
  cin >> A >> P;

  int frag;

  frag = P + 3*A;

  int ans = frag / 2;

  cout << ans << endl;
}
