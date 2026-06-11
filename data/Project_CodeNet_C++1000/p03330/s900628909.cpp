#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000000000

int main(){
  int N,C;
  cin>>N>>C;
  vector<vector<int>> D(C,vector<int>(C)),c(N,vector<int>(N));
  for(int i=0;i<C;i++){
    for(int j=0;j<C;j++){
      cin>>D.at(i).at(j);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>c.at(i).at(j);
    }
  }
  vector<vector<int>> count(3,vector<int>(C,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      count.at((i+j)%3).at(c.at(i).at(j)-1)++;
    }
  }
  int ans=1000000000;
  for(int i=0;i<C;i++){
    for(int j=0;j<C;j++){
      if(j==i){
        continue;
      }
      for(int k=0;k<C;k++){
        if(k==i||k==j){
          continue;
        }
        int ans2=0;
        for(int color=0;color<C;color++){
          ans2+=count.at(0).at(color)*D.at(color).at(i);
          ans2+=count.at(1).at(color)*D.at(color).at(j);
          ans2+=count.at(2).at(color)*D.at(color).at(k);
        }
        ans=min(ans,ans2);
      }
    }
  }
  cout<<ans<<endl;
}
