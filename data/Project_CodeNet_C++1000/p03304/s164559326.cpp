#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000000+7
typedef long long int lint;

int main() {
  double n,m,d;
  double ans;
  cin >> n >> m >> d;
  
  if(d == 0){
    ans = (m-1)/n;
  }
  else{
    ans = (2*(n-d)*(m-1))/(n*n);
  }
  cout << fixed << setprecision(15);
  co(ans);
}