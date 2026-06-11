#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;

double dp[305][305][305];
bool check[305][305][305];

double n;
double calc(ll a,ll b,ll c){
    if (check[a][b][c]==true){
    //  cout<<"true"<<endl;
        return dp[a][b][c];
    }
  double p0=double((n-a-b-c)/n);
  double p1=double(a/n);
  double p2=double(b/n);
  double p3=double(c/n);

  double now=1;
  //cout<<n<<"n"<<(n-a-b-c)<<"a"<<endl;
  if (a>0)now+=p1*calc(a-1,b,c);
  if (b>0)now+=p2*calc(a+1,b-1,c);
  if (c>0)now+=p3*calc(a,b+1,c-1);
//  cout<<now<<"now"<<p0<<"p0"<<endl;
  dp[a][b][c]=double(now/(1-p0));
  check[a][b][c]=true;
  //cout<<dp[a][b][c]<<"a"<<a<<"b"<<b<<"c"<<c<<endl;
    return dp[a][b][c];

}

int main() {
  cin>>n;
  vector<ll> a(n);
  vector<ll> c(3,0);

  rep(i,n){
    cin>>a[i];
    if (a[i]==1)c[0]++;
    if (a[i]==2)c[1]++;
    if (a[i]==3)c[2]++;
  }
//  dp[0][0][0]=0;

    rep(i,305)rep(j,305)rep(k,305){
    dp[i][j][k]=0;
    check[i][j][k]=false;
}
  check[0][0][0]=true;
rep(i,c[0]+1)rep(j,c[1]+1)rep(k,c[2]+1){
  dp[i][j][k]=calc(i,j,k);
  check[i][j][k]=true;
}
//cout<<c[0]<<endl;

cout<<setprecision(10)<<dp[c[0]][c[1]][c[2]];
}
