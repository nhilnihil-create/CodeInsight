#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<long> xv(n);
  vector<long> yv(m);
  for(long i=0;i<n;i++) cin >> xv[i];
  for(long i=0;i<m;i++) cin >> yv[i];
  sort(xv.begin(),xv.end());
  sort(yv.begin(),yv.end());
  if(max(x,xv[n-1])<min(y,yv[0])) cout << "No ";
  cout << "War" << endl;
}