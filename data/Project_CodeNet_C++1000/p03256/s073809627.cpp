#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

char S[200500];
vector<int> gph[200500];
int deg[200500][2];
bool chk[200500];

int que[200500 * 4]; int qf, qr;

int main()
{
    int N, M; scanf("%d%d%s", &N, &M, S+1);
    for(int i = 1; i <= N; i++) {
      gph[i].clear();
      S[i] = (S[i] == 'B');
      chk[i] = false;
      deg[i][0] = deg[i][1] = 0;
    }
    for(int i = 1; i <= M; i++) {
      int a, b; scanf("%d%d", &a, &b);
      for(int rep = 0; rep < 2; rep++) {
        gph[a].push_back(b);
        deg[b][S[a]] += 1;
        swap(a, b);
      }
    }

    qf = qr = 0;

    for(int i = 1; i <= N; i++) {
      if(deg[i][0] == 0 || deg[i][1] == 0) {
        que[++qr] = i;
        chk[i] = true;
      }
    }

    while(qf < qr) {
      int u = que[++qf];
      for(int v : gph[u]) {
        deg[v][S[u]] -= 1;
        if(!chk[v] && (deg[v][0] == 0 || deg[v][1] == 0)) {
          que[++qr] = v;
          chk[v] = true;
        }
      }
    }

    puts(qr < N ? "Yes" : "No");

	return 0;
}