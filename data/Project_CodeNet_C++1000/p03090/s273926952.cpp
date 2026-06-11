#include <bits/stdc++.h>
#define FR first
#define SE second

using namespace std;

typedef pair<int,int> pr;

vector <pr> ans;

int main() {
  int n;
  scanf("%d",&n);
  int m=((n&1)?n:n+1);
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if (i+j!=m) ans.push_back(pr(i,j));
  printf("%d\n",ans.size());
  for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].FR,ans[i].SE);
  return 0;
}
