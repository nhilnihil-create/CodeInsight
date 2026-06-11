//Link : https://atcoder.jp/contests/agc013/tasks/agc013_b
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define N 1000005

bool vis[N];
int ret[N];
void solve() {
  int m,k;scanf("%d %d ", &m,&k);
  int r = (1<<m)-1;


  if(k<=r) {
    if(k==0) {
      for(int i=0;i<=r;++i) {
        printf("%d %d ", i,i);
      }
      putchar('\n');
      return;
    } if(m==1) {
      printf("-1\n");
      return;
    } else {
      int check = k&(k-1);
      vector<int> go;
      vis[k] = true;
      if(check==0) {
        //2^x
        go.push_back(r);
        vis[r] = true;
        for(int i=0;i<m;++i) {
          if( (k&(1<<i)) ==0) {
            go.push_back(1<<i);
            vis[1<<i] = true;
          }
        }
      } else {
        for(int i=0;i<m;++i) {
          if( (k&(1<<i)) ) {
            go.push_back(1<<i);
            vis[1<<i] = true;
          }
        }
      }
      int pos = 0;

      for(int i=0;i<go.size();++i) {
        ret[pos++] = go[i];
      }
      for(int i=0;i<=r;++i) {
        if(!vis[i]) {
          ret[pos++] = i;
        }
      }
      ret[pos++] = k;
      for(int i=r;i>=0;--i) {
        if(!vis[i]) {
          ret[pos++] = i;
        }
      }
      for(int i=go.size()-1;i>=0;--i) {
        ret[pos++] = go[i];
      }

      ret[pos++] = k;
      for(int i=0;i<pos;++i) {
        printf("%d ", ret[i]);
      }
      putchar('\n');
    }
  } else {
    printf("-1\n");
  }
}
int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
