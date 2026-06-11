#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N,M,X;
  cin >> N >> M >> X;

  int A[N];
  for(int i = 1; i <= M; i++){
    int a; cin >> a;
    A[a] = 1;
  }

  // N 
  int df = 0;
  for(int i = X + 1; i < N; i++){
    if(A[i] == 1) df++;
  }
  int db = 0;
  for(int i = X - 1; i >0; i--){
    if(A[i] == 1) db++;
  }
  int ans = min(df,db);
  cout << ans << endl;




	return 0;
}

