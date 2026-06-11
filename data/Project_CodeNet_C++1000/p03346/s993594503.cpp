#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) a[i]--;
  int b[n]; for(int i=0;i<n;i++) b[a[i]]=i;

  // 1つ以上連続する値
  int an=n-1;
  for(int i=1,sm=n-1,nw=b[0];i<n;i++) {
    if (nw < b[i]) sm--, nw=b[i], an=min(an,sm);
    else sm=n-1, nw=b[i];
  }
  cout<<an<<endl;
}