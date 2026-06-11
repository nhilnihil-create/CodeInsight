#include <bits/stdc++.h>
using namespace std;

int N,C;

int calc(vector<vector<int>> &D,vector<int> &cnt,int x){
  int ans=0;
  for(int i=0;i<C;i++){
    ans+=D.at(i).at(x)*cnt.at(i);
  }
  return ans;
}

int main(){
  cin >> N >> C;
  vector<vector<int>> D(C,vector<int>(C));
  for(int i=0;i<C;i++){
    for(int j=0;j<C;j++){
      cin >> D.at(i).at(j);
    }
  }
  vector<vector<int>> c(N,vector<int>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> c.at(i).at(j);
      c.at(i).at(j)--;
    }
  }

  vector<vector<int>> cnt(3,vector<int>(C,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cnt.at((i+j)%3).at(c.at(i).at(j))++;
    }
  }
  int ans=1e9;
  for(int i=0;i<C;i++){
    for(int j=0;j<C;j++){
      for(int k=0;k<C;k++){
        if(i==j || j==k || k==i)  continue;
        int tmp0=calc(D,cnt.at(0),i);
        int tmp1=calc(D,cnt.at(1),j);
        int tmp2=calc(D,cnt.at(2),k);
        ans=min(ans,tmp0+tmp1+tmp2);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
