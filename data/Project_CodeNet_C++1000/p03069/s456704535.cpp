#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  int N;
  string S;
  cin>>N>>S;
  vector<int> sum_black(N+1,0);
  for(int i=0;i<N;i++){
    if(S.at(i)=='#'){
      sum_black.at(i+1)+=1;
    }
    sum_black.at(i+1)+=sum_black.at(i);
  }

  int ans=N;
  for(int i=0;i<=N;i++){
    ans=min(sum_black.at(i)+N-i-(sum_black.at(N)-sum_black.at(i)),ans);
  }
  cout<<ans<<endl;
}
