#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, M; cin >> N >> M;
  
  int X[M]; rep(i,M) cin >> X[i];
  sort(X, X+M);
  if (N>M){
    cout << 0 << endl;
    return 0;
  }  

  int a[M];
  rep(i,M){
    if (i==0) a[0] = 0;
    else a[i] = X[i] - X[i-1];
  }
  
  sort(a,a+M,greater<int>());
  int tot = X[M-1] - X[0];
  rep(i,N-1) tot -= a[i];

  cout << tot << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}

