#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int H,W,D;
  cin>>H>>W>>D;
  VVI A(H,VI(W));
  vector<pair<int,P> > PP;
  rep(i,H) rep(j,W){
    cin>>A[i][j];
    PP.push_back(make_pair(A[i][j],make_pair(i,j)));
  }
  sort(all(PP));
  int Q;
  cin>>Q;
  VI L(Q),R(Q);
  rep(i,Q) cin>>L[i]>>R[i];
  vector<ll> X(H*W);
  rep(i,H*W){
    if(i>=D){
      X[i]=X[i-D]+abs(PP[i].second.first-PP[i-D].second.first)+abs(PP[i].second.second-PP[i-D].second.second);
    }
  }
  rep(i,Q){
    cout<<X[R[i]-1]-X[L[i]-1]<<endl;
  }
}