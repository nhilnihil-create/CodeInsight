#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  vector<int> a(3), b(3);
  vector<int> cnt(4);
  rep(i, 3) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cnt[a]++;
    cnt[b]++;
  }

  sort(cnt.rbegin(), cnt.rend());
  if (cnt[0] == 2 && cnt[1] == 2 && cnt[2] == 1 && cnt[3] == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}