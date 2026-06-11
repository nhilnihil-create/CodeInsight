#include <bits/stdc++.h>
using namespace std;
int MAX_INT = 1e9;
int N,A,B,C;
int l[1000];
int dfs(int cur,int a,int b,int c) {
  if(cur==N) return (min(a,min(b,c))>0)?abs(a-A)+abs(b-B)+abs(c-C)-30:MAX_INT;
  return min(min(dfs(cur+1,a,b,c),dfs(cur+1,a+l[cur],b,c)+10),min(dfs(cur+1,a,b+l[cur],c)+10,dfs(cur+1,a,b,c+l[cur])+10));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> A >> B >> C;
  for(int i = 0; i < N; i++) cin >> l[i];
  cout << dfs(0, 0, 0, 0) << endl;
  return 0;
}
