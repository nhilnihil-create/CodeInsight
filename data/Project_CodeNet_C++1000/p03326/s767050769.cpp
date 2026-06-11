#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000000+7
typedef long long int lint;

int main (){
  lint N,M,sum,ans = 0,op_x = -1,op_y = -1,op_z = -1;
  cin >> N >> M;
  vector<lint> x(N),y(N),z(N),SUM(N);
  rep(i,0,N){cin >> x[i] >> y[i] >> z[i];}
  
  rep(j,0,8){
    sum = 0;
    if(j%4 == 0){op_x *= -1;}
    if(j%2 == 0){op_y *= -1;}
    op_z *= -1;
    rep(i,0,N){
      SUM[i] = op_x*x[i] + op_y*y[i] + op_z*z[i];
    }
    sort(SUM.begin(),SUM.end());
    reverse(SUM.begin(),SUM.end());
    rep(i,0,M){
      sum += SUM[i];
    }
    ans = max(sum,ans);
  }
  co(ans);
}