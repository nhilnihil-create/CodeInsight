#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
  int n,m,Q; cin >> n >> m >> Q;
  vector<vector<int> > train(n+1,vector<int>(n+1,0));
  rep(i,m){
      int L,R; cin >> L >> R;
      train[L][R]++;
  }

  rep(i,n)rep(j,n){
      train[i+1][j+1]+=train[i+1][j];
  }

  rep(i,n)rep(j,n){
      train[i+1][j+1]+=train[i][j+1];
  }
 
  vector<int> ans(Q,0);

  rep(i,Q){
    int p,q; cin >> p >> q;
    ans[i]=train[q][q]-train[q][p-1]-train[p-1][q]+train[p-1][p-1];
  }

  rep(i,Q) cout << ans[i] << endl;
return 0;
}