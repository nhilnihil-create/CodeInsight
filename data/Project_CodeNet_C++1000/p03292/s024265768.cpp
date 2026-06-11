#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  vector<int> vec(3);
  rep(i,0,3) cin >>vec[i];
  sort(vec.begin(),vec.end());
  int ans=0;
  rep(i,0,2) ans+=vec[i+1]-vec[i];
  cout <<ans <<endl;
  return 0;
}
