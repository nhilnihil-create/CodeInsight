#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  vector<vector<int>> c(3, vector<int>(3));
  rep(i,3)rep(j,3) cin >> c.at(i).at(j);

  bool flag=true;
  vector<int> sa(4);
  sa.at(0) = c.at(0).at(0)-c.at(0).at(1);
  sa.at(1) = c.at(0).at(1)-c.at(0).at(2);
  sa.at(2) = c.at(0).at(0)-c.at(1).at(0);
  sa.at(3) = c.at(1).at(0)-c.at(2).at(0);

  rep(i,3){
    if(sa.at(0)!=(c.at(i).at(0)-c.at(i).at(1))) flag=false;
    if(sa.at(1)!=(c.at(i).at(1)-c.at(i).at(2))) flag=false;
    if(sa.at(2)!=(c.at(0).at(i)-c.at(1).at(i))) flag=false;
    if(sa.at(3)!=(c.at(1).at(i)-c.at(2).at(i))) flag=false;
  }

  if(flag) cout << "Yes";
  else cout << "No";
}