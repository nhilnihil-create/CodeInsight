#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  const int n = 3;
  vector<int> cnt(4);

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    cnt[a]++;
    cnt[b]++;
  }

  bool ans = true;
  // 入力される頂点の数がそれぞれ3以上だったらNG
  // 1 -- 2 -- 3 -- 4 みたいな形になれば一本道で行けるので、この場合カウントは 1, 2, 2, 1になる
  rep(i, 4) { 
    if(cnt[i] >= 3) ans = false;
  }
  
  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;

  

}