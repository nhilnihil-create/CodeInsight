#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
  vector<int>a(3);
  int i;
  rep(i,3) cin >> a[i];
  sort(a.begin(),a.end());
  cout << abs(a[i]-a[i+1])+abs(a[i+1]-a[i+2]) << endl;
  return 0;
}