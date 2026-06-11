#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define ALLTRUE(xs) all_of(ALL(xs),[](bool x){return x;})
#define AND(x,y,z) set_intersection((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define ANYTRUE(xs) any_of(ALL(xs),[](bool x){return x;})
#define CONCAT(x,y) (x).insert((x).end(),(y).begin(),(y).end())
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define FOR(i,a,b) for (int i=(int)(a);i<(int)(b);++i)
#define OR(x,y,z) set_union((x).begin(),(x).end(),(y).begin(),(y).end(),inserter((z),(z).end()))
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  ll N,K;cin>>N>>K;

  if (K==0) {
    OUT(N*N);
    return 0;
  }

  // bに入りうる値でループ
  ll ans = 0;
  FOR(b,K+1,N+1) {
    // 余りがK以上になる個数
    // 境界線を見つけて、そこまで足していく
    // ....ooo....ooo....oo|o
    // あまりの島が全部入っている個数
    int gap = b-K;
    int island_cnt = N/b;
    ans += gap*island_cnt;

    // 最後の島が境界線に分断されている場合
    if ((b*island_cnt+K-1)<=N) {
      ans += N-(b*island_cnt+K-1);
    }
  }
  OUT(ans);

  return 0;
}