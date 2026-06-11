#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<int>xr(n);
  vector<int>yr(m);
  for(int i=0;i<n;i++)
    cin >> xr.at(i);
  for(int i=0;i<m;i++)
    cin >> yr.at(i);
  sort(xr.begin(),xr.end(),greater());
  sort(yr.begin(),yr.end());
  cout << ((xr.at(0)<yr.at(0)&&x<y&&xr.at(0)<y&&x<yr.at(0))?"No War":"War") << endl;
  return 0;
}