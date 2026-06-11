#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000000+7
typedef long long int lint;

int main() {
  int ans = 0;
  vector<int> A(3);
  rep(i,0,3){cin >> A[i];}
  sort(A.begin(),A.end());
  ans = A[2] - A[0];
  co(ans);
}