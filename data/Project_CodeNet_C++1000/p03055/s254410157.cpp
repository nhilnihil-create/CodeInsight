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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  VI A(N-1),B(N-1);
  rep(i,N-1) cin>>A[i]>>B[i];
  VVI X(N,VI());
  rep(i,N-1){
    X[A[i]-1].pb(B[i]-1);
    X[B[i]-1].pb(A[i]-1);
  }
  VI D(N,-1);
  D[0]=0;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int tmp=Q.front();
    Q.pop();
    rep(i,X[tmp].size()){
      if(D[X[tmp][i]]==-1){
        D[X[tmp][i]]=D[tmp]+1;
        Q.push(X[tmp][i]);
      }
    }
  }
  int Y=0;
  rep(i,N) if(D[Y]<D[i]) Y=i;
  rep(i,N) D[i]=-1;
  D[Y]=0;
  Q.push(Y);
  while(!Q.empty()){
    int tmp=Q.front();
    Q.pop();
    rep(i,X[tmp].size()){
      if(D[X[tmp][i]]==-1){
        D[X[tmp][i]]=D[tmp]+1;
        Q.push(X[tmp][i]);
      }
    }
  }
  int L=0;
  rep(i,N) if(L<D[i]) L=D[i];
  if(L%3!=1) cout<<"First"<<endl;
  else cout<<"Second"<<endl;
}
