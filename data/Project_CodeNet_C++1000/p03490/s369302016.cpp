#include<bits/stdc++.h>
using namespace std;

char s[8008];
int ex, ey;
bool dp[2][16006];
vector<int> dv[2];

bool foo(int dist, vector<int> & mv) {
  memset(dp,0,sizeof(dp));
  int f = 0;
  dp[0][8000] = true;
  for(int x : mv) {
    for(int i=0;i<=16000;i++) {
      if(!dp[f][i]) continue;
      dp[!f][i+x] = dp[!f][i-x] = true;
    }
    memset(dp[f],0,sizeof(dp[f]));
    f = !f;
  }
  return dp[f][dist];
}

int main() {
  scanf("%s%d%d",s,&ex,&ey);
  ex += 8000;
  ey += 8000;
  int i=0;
  while(s[i] == 'F') {
    i++;
    ex--;
  }
  if(ex<0) {
    puts("No");
    return 0;
  }
  int d=0, dir=0;
  for(;s[i];i++) {
    if(s[i] == 'T') {
      if(d) dv[dir].push_back(d);
      dir = !dir;
      d = 0;
    } else {
      d++;
    }
  }
  if(d) dv[dir].push_back(d);
  puts((foo(ex, dv[0]) && foo(ey, dv[1]))?"Yes":"No");

}
