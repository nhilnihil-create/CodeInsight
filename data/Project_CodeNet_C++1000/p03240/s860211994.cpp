#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int 
main() {

  int N; cin >> N;
  vector<int> arrx(N), arry(N), arrh(N);
  rep(i, 0, N){
    cin >> arrx[i] >> arry[i] >> arrh[i];
  }

  int start = 0;
  if(arrh[0] <= 0){
    int i = 0;
    while(arrh[i] == 0){
      i++;
    }
    start = i;
  }

  rep(x, 0, 101){
    rep(y, 0, 101){
      bool flag = true;
      int ansh = arrh[start] + abs(x - arrx[start]) + abs(y - arry[start]);
      rep(l, 0, N){
        if(arrh[l] > 0){
          int comp = arrh[l] + abs(x - arrx[l]) + abs(y - arry[l]);
          if(ansh != comp) flag = false;
        }
        if(arrh[l] == 0){
          int tmp = abs(x - arrx[l]) + abs(y - arry[l]);
          if(ansh> tmp) flag = false;
        }
      }
      if(flag) cout << x << " " << y << " " << ansh << endl;
    }
  }


}
