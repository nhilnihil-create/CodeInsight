#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int n,q,a[N],ca[N],p[N],freq[N];
bool vis[N],comp[N];

int par(int u) {
   return p[u] == u ? u : p[u] = par(p[u]);
}

void join(int u , int v) {
   p[par(u)] = par(v);
}

bool sameset(int u , int v) {
   return par(u) == par(v);
}

int main() {
   for (int i = 0 ; i < N ; i++) p[i] = i;
   scanf("%d%d" , &n , &q);
   for (int i = 1 ; i <= n ; i++) {
      scanf("%d" , &a[i]);
   }
   while (q--) {
      int u,v; scanf("%d%d" , &u , &v);
      join(u , v);
   }
   vector <int> keep[N],keep1[N];
   for (int i = 1 ; i <= n ; i++) {
      keep[par(i)].push_back(a[i]);
      keep1[par(i)].push_back(i);
   }
   int sol = 0;
   for (int i = 1 ; i <= n ; i++) {
      if (!vis[par(i)]) {
         vis[par(i)] = true;
         for (int j = 0 ; j < keep[par(i)].size() ; j++) {
            freq[keep[par(i)][j]]++;
            freq[keep1[par(i)][j]]++;
         }
         for (int j = 0 ; j < keep[par(i)].size() ; j++) {
            if (freq[keep[par(i)][j]] == 2 && !comp[keep[par(i)][j]]) {
               sol++;
               comp[keep[par(i)][j]] = true;
            }
            if (freq[keep1[par(i)][j]] == 2 && !comp[keep1[par(i)][j]]) {
               sol++;
               comp[keep1[par(i)][j]] = true;
            }
            freq[keep[par(i)][j]] = 0, freq[keep1[par(i)][j]] = 0;
         }
      }
   }
   printf("%d\n" , sol);
}
