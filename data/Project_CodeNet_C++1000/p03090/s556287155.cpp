#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int frag;
  if(n%2) frag = n;
  else frag = n+1;
  int ans = n *(n -1) /2;
  ans -= n/2;
  cout << ans << endl;
  for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
    if(i+j == frag) continue;
    printf("%d %d\n",i,j);
  }
}