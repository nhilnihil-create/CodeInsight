#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n,m,q;
int a[505][505];

int main(){
  cin >> n >> m >> q;
  rep(i,0,m){
    int l,r;
    cin >> l >> r;
    a[1][r]++;//cout << 1 << r;
    a[l+1][r]--; //cout << l+1 << r << endl;
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      a[i][j] += a[i][j-1];
    }
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      a[i][j] += a[i-1][j];
    }
  }

  rep(i,0,q){
    int s,t;
    cin >> s >> t;
    cout << a[s][t] << endl;
  }

  return 0;
}
