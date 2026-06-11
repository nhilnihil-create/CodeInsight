#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>x(3);
  for(int i=0;i<3;i++) cin>>x[i];
  sort(x.begin(),x.end());
  int ans=x[0]+x[1]+10*x[2];
  cout<<ans<<endl;
}
