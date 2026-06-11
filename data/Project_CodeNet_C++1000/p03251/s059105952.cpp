#include<bits/stdc++.h>
using namespace std;
//<<setprecision(30)
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;
 
int main(){
  int N,M,X,Y; cin>>N>>M>>X>>Y;
  vector<int> x(N),y(M);
  rep(i,N)cin>>x.at(i);
  rep(i,M)cin>>y.at(i);
  sort(begin(x),end(x));
  sort(begin(y),end(y));
  int xm = x.at(N-1), ym = y.at(0);
  if(xm<=ym){
    if(min(ym,Y)-max(xm,X)>0){
      cout<<"No War"<<endl;
      return 0;
    }
  }
  cout<<"War"<<endl;
}