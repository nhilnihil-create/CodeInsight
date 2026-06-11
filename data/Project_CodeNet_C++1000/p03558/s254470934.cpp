
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <deque>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

int k;

const int INF = 10000000;
int dist[100000+10];

int go(void) {
  REP(i, 100000+10) {
    dist[i] = INF;
  }
  deque<pair<int,int> > q;
  q.push_back(make_pair(1, 1));
  dist[1] = 1;
  while(!q.empty()) {
    pair<int,int> cur = q.front(); q.pop_front();
    if(dist[cur.first] < cur.second) {
      continue;
    }
    if(cur.first == 0) {
      break;
    }
    int n10 = (cur.first*10) % k;
    if(cur.second < dist[n10]) {
      q.push_front(make_pair(n10, cur.second));
      dist[n10] = cur.second;
    }
    int n1 = (cur.first+1) % k;
    if(cur.second+1 < dist[n1]) {
      q.push_back(make_pair(n1, cur.second + 1));
      dist[n1] = cur.second+1;
    }
  }
  return dist[0];
}

int main(void) {
  while(~scanf("%d", &k)) {
    int res = go();
    printf("%d\n", res);
  }
  return 0;
}
