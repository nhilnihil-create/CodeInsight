#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n = 5;
  vector<int> time(n);
  rep(i,n) cin >> time[i];
  vector<int> N_time(n);
  
  rep(i,n){
    if(time[i]%10==0) N_time[i] = time[i];
    else N_time[i] = time[i]-time[i]%10+10;
  }

  int ans = INF;
  rep(i,n){
    int tmp = 0;
    rep(j,n){
      if(j!=i) tmp+=N_time[j];
    }
    tmp+=time[i];
    ans = min(ans,tmp);
  }

  cout << ans << endl;
  
  return 0;
}
