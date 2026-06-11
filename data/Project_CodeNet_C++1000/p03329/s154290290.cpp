#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  queue<long> num;
  long ans[n+1];
  rep(i,n+1)ans[i] = 0;
  num.push(0);
  ans[0] = 0;
  while(num.size()){
    long now = num.front();
    num.pop();
    if(now==n)break;
    if(ans[now+1]==0){
      num.push(now + 1);
      ans[now+1] = ans[now] + 1;
    }
    rep(i,6){
      long tmp = now + pow(6,i+1);
      if(tmp > n || ans[tmp] != 0)continue;
      num.push(tmp);
      ans[tmp] = ans[now] + 1;
    }
    rep(i,5){
      long tmp = now + pow(9,i+1);
      if(tmp > n || ans[tmp] != 0)continue;
      num.push(tmp);
      ans[tmp] = ans[now] + 1;
    }
  }
  cout << ans[n] << endl;
  return 0;
}