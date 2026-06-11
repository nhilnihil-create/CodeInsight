#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
    int minn=min(min(min(min(a,b),c),d),e);
  int maxx=max(max(max(max(a,b),c),d),e);
  if(maxx-minn<=k)cout<<"Yay!";
    else cout<<":(";
}
