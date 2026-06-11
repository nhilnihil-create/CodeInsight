#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  vi time(5);
  rep(i,5) cin >> time[i];
  sort(time.begin(),time.end());
  int ans = 10000000;
  do{
    int t=0;
    rep(i,5){
      if(i!=4) t += (time[i]+9)/10*10;
      else t += time[i];
    }
    ans = min(ans, t);
  }while(next_permutation(time.begin(),time.end()));
  cout << ans << endl;
}
