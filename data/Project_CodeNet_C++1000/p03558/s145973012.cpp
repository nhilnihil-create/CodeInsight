#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define MAXN 100000
#define INF ( 1LL << 60 )
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long ll;

using namespace std;

int color[MAXN];
ll d[MAXN];

ll bfs ( ll K )
{
  deque<ll> Q;
  ll now = 1;

  for ( int i = 0; i < K; ++i ) color[i] = WHITE, d[i] = INF;
  Q.push_front(1);
  color[now%K] = GRAY;
  d[now%K] = 1;

  while(!Q.empty())
  {
    now = Q.front(); Q.pop_front();
    if ( color[now%K] == BLACK ) continue;

    //cout << "now = " << now <<", now mod/k = " << now%K << "\n";

    ll tmp1,tmp2;
    tmp1 = now*10;
    //cout << "tmp1 mod/k = " << tmp1%K << "\n";
    if ( color[tmp1%K] != BLACK ) {
      if ( d[tmp1%K] > d[now%K] ) {
        d[tmp1%K] = d[now%K];
        Q.push_front(tmp1%K);
        if ( color[tmp1%K] == WHITE ) color[tmp1%K] = GRAY;
      }
    }

    tmp2 = now+1;
    //cout << "tmp2 mod/k = " << tmp2%K << "\n";
    if ( color[tmp2%K] != BLACK ) {
      if ( d[tmp2%K] > d[now%K]+1 ) {
        d[tmp2%K] = d[now%K]+1;
        Q.push_back(tmp2%K);
        if (color[tmp2%K] == WHITE ) color[tmp2%K] = GRAY;
      }
    }

    color[now%K] = BLACK;

  //  cout << "\n";
  }

  /*
  for ( int i = 0; i < K; ++i ) {
    printf("node%d = %d\n", i, d[i]);
  }
  */
  return d[0];
}

int main()
{
  ll K;

  cin >> K;

  cout << bfs(K) << "\n";
}
