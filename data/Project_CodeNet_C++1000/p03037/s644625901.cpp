#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n,m;
cin >> n >> m;
vector<vector<int>> a(m,vector<int>(2));
rep(i,m)rep(j,2) cin >> a.at(i).at(j);
int lft = -1,rgt = 1000000;
rep(i,m)rep(j,2){
  lft = max(lft,a.at(i).at(0)) ;
  rgt = min(rgt,a.at(i).at(1)) ;
}
int ans = rgt - lft +1;
cout << (ans>=0?ans:0)<< endl;
}
