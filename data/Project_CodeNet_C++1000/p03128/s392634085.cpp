#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  for(int i=0;i<M;i++)  cin >> A.at(i);

  vector<int> cnt={0,2,5,5,4,5,6,3,7,6};
  sort(A.begin(),A.end());

  vector<int> dp(N+1,0);
  dp.at(0)=1;
  for(int i=0;i<M;i++){
    int x=cnt.at(A.at(i));
    for(int j=0;j<N+1;j++){
      if(j-x<0) continue;
      if(dp.at(j-x)==0) continue;
      dp.at(j)=max(dp.at(j),dp.at(j-x)+1);
    }
  }
  string ans="";
  int now=N;
  for(int i=M-1;i>=0;i--){
    int x=cnt.at(A.at(i));
    for(;now>=0;){
      if(now-x<0) break;
      if(dp.at(now-x)==0) break;
      if(dp.at(now)==dp.at(now-x)+1){
        ans+=(A.at(i)+'0');
        now-=x;
      }
      else  break;
    }
  }
  cout << ans << endl;

  return 0;
}
