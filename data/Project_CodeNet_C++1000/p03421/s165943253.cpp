#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll N,A,B;

int main(){
  cin>>N>>A>>B;

  if(A+B-1>N||A*B<N){
      cout<<-1<<endl;
      return 0;
  }

  int now=min(N-A,B-1);
  vector<int> ans;
  vector<int> used(N+1,0);
  for(int i=N-A+1;i<=N;i++){
      ans.push_back(i);
      used[i]=1;
      for(int j=0;j<B-1;j++){
          if(now-j>=1&&used[now-j]==0){
              used[now-j]=1;
              ans.push_back(now-j);
          }else break;
      }
      now=min(N-A,now+B-1);
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
  cout<<endl;

  return 0;
}
