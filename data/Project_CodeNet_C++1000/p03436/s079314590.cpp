#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll R,C,B=0;
  cin >> R >> C;
  vector<string> X(R);
  rep(i,R){
    cin >> X.at(i);
    rep(j,C){
      if(X.at(i).at(j)=='#'){
        B++;
      }
    }
  }

    queue<P> Q;
    vector<vector<ll>> D(R,vector<ll>(C,INF));
    Q.push(P(0,0));
    D.at(0).at(0)=0;
    while(!Q.empty()){
      ll y,x;
      y=Q.front().first;
      x=Q.front().second;
      Q.pop();
      if(y!=R-1&&D.at(y+1).at(x)==INF&&X.at(y+1).at(x)!='#'){
        D.at(y+1).at(x)=D.at(y).at(x)+1;
        Q.push(P(y+1,x));
      }
      if(y!=0&&D.at(y-1).at(x)==INF&&X.at(y-1).at(x)!='#'){
        D.at(y-1).at(x)=D.at(y).at(x)+1;
        Q.push(P(y-1,x));
      }
      if(x!=C-1&&D.at(y).at(x+1)==INF&&X.at(y).at(x+1)!='#'){
        D.at(y).at(x+1)=D.at(y).at(x)+1;
        Q.push(P(y,x+1));
      }
      if(x!=0&&D.at(y).at(x-1)==INF&&X.at(y).at(x-1)!='#'){
        D.at(y).at(x-1)=D.at(y).at(x)+1;
        Q.push(P(y,x-1));
      }
    }
  if(D.at(R-1).at(C-1)==INF){
    cout << -1 << endl;
  }else{
  cout << R*C-B-1-D.at(R-1).at(C-1) << endl;
  }
}