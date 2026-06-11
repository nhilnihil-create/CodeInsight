#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)


int main() {
  int N,M,a,b;
  cin >> N >> M;
  vector<vector<int>> ab(M,vector<int>(2));
  rep(i,M) {
    cin >> a >> b;
    a--;b--;
    ab[i] = {a,b};
  }
  sort(ab.begin(),ab.end());
  int cnt=0,now=-1;
  rep(i,M) {
    if (now<=ab[i][0]) {
      cnt++;
      now = ab[i][1];
    }
    else if (ab[i][1]<now) now = ab[i][1];

  }
  cout << cnt << endl;
}