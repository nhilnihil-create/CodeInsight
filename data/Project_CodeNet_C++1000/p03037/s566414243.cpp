#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int l[m],r[m];
  for(int i=0;i<m;i++)cin >> l[i] >> r[i];
  sort(l,l+m,greater<int>());
  sort(r,r+m);
  if(r[0]-l[0]>=0)cout << r[0]-l[0]+1 << endl;
  else cout << 0 << endl;
}
