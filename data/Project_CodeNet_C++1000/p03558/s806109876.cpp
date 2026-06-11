#include<cstdio>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;
const int N = 100010;
const int M = N << 1;
int dis[N];
int k;
int tot, head[N], pre[M], ver[M], val[M];
int vis[N];
void add(int x, int y, int z) {
  ver[++tot] = y, val[tot] = z, pre[tot] = head[x], head[x] = tot;
}
void build() {
  for(int i = 1; i < k; i++) {
    add(i, (i + 1) % k, 1);
  }
  for(int i = 1; i < k; i++) {
    add(i, (i * 10) % k, 0);
  }

}
int main() {
  scanf("%d", &k);
  build();
  memset(dis, 0x3f, sizeof(dis));
  priority_queue< pair<int, int> > q;
  q.push(make_pair(-1, 1));
  dis[1] = 1;
  while(!q.empty()) {
    int x = q.top().second; q.pop();
    if(vis[x]) continue;
    vis[x] = 1;
    for(int i = head[x]; i; i = pre[i]) {
      int y = ver[i], v = val[i];
      if(dis[y] > dis[x] + v) {
	dis[y] = dis[x] + v;
	q.push(make_pair(-dis[y], y));
      }
    }
  }
  printf("%d", dis[0]);
  return 0;
}
