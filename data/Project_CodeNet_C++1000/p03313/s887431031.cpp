#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
/*
各bitがKより小さいi,jでA_i,A_jが一番大きいものをdp[K][0],dp[K][1]とする(i,jが入ってる)
答えは当然dp[K][0]+dp[K][1]
dp[K][0]とdp[K][1]の求め方は、Kの立ってるbitを1つ外した数字Lに対してのdp[L][0]とdp[L][1]、A[K]を見ればいいので
40個くらい見ればいいはず
*/
int dp[1234567][3];
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(1234567);
  for(int i=0;i<pow(2,N);i++)cin>>v[i];
  typedef pair<int,int> P;
  set<int> s;
  priority_queue<P> que;
  int mx=0;dp[0][0]=0;
  for(int i=1;i<pow(2,N);i++){
    s.clear();
    for(int j=0;j<N;j++){
      if((i>>j)&1){
        s.insert(dp[i^(1<<j)][0]);
        if((i^(1<<j)))s.insert(dp[i^(1<<j)][1]);
      }
    }
    //cout<<i<<" "<<s.size()<<endl;
    while(que.size())que.pop();//que.clear();
    for(int p:s)que.push(P(v[p],p));
    que.push(P(v[i],i));
    dp[i][0]=que.top().second;que.pop();
    dp[i][1]=que.top().second;que.pop();
    //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<v[dp[i][0]]+v[dp[i][1]]<<endl;
    mx=max(mx,v[dp[i][0]]+v[dp[i][1]]);
    cout<<mx<<endl;
  }
}
