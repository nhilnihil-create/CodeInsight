#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N;
  cin>>N;
  vector<int> C(N);
  for(int i=0;i<N;i++){
    cin>>C.at(i);
  }
  vector<vector<int>> index(200001);
  for(int i=0;i<N;i++){
    index.at(C.at(i)).push_back(i);
  }

  vector<ll> dp(N+1,0);
  dp.at(0)=1;
  for(int i=0;i<N;i++){
    dp.at(i+1)+=dp.at(i);
    dp.at(i+1)%=MOD;
    if(i<N-1){
      if(C.at(i)==C.at(i+1)){
        continue;
      }
    }
    int c=C.at(i);
    int k=upper_bound(index.at(c).begin(),index.at(c).end(),i+1)-index.at(c).begin();
    if(k==index.at(c).size()){
      continue;
    }
    dp.at(index.at(c).at(k))+=dp.at(i);
    dp.at(index.at(c).at(k))%=MOD;
  }
  cout<<dp.at(N-1)<<endl;
}
