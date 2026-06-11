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
  vector<vector<int> > train(n,vector<int>(n+1,0));
  rep(i,m){
      int L,R; cin >> L >> R;
      L--;
      train[L][R]++;
  }

  rep(i,n)rep(j,n){
      train[i][j+1]+=train[i][j];
  }
 
  vector<int> ans(Q,0);

  rep(i,Q){
    int p,q; cin >> p >> q;
    p--;
    for(int j=p; j<q; j++){
        ans[i]+=train[j][q]-train[j][0];
    }
  }

  rep(i,Q) cout << ans[i] << endl;
return 0;
}