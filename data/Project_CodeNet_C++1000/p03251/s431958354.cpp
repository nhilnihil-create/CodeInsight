#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  int left=-100;
  int right=100;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    left=max(a,left);
  }
  for(int i=0;i<m;i++){
    int b;
    cin>>b;
    right=min(b,right);
  }
  string ans="War";
  for(int i=x+1;i<=y;i++){
    if(left<i && i<=right) ans="No War";
  }
  cout<<ans<<endl;
}
