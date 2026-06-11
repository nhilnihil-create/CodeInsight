#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
ll MOD = 1000000007;

int main() {
  ll N,Y;
  cin >> N >> Y;
  Y /= 1000;
  bool flag = false;
  for(ll yukiti = 0;yukiti<=N;yukiti++){
    for(ll itiyou = 0;itiyou <= N-yukiti;itiyou++){
      ll hideyo = N-yukiti-itiyou;
      if(yukiti*10+itiyou*5+hideyo == Y){
        flag = true;
        cout << yukiti << " " << itiyou << " " << hideyo << endl;
        break;
      }
    }
    if(flag){
      break;
    }
  }
  if(!flag){
    cout << "-1 -1 -1" << endl;
  }
}
    