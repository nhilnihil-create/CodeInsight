#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int h,w;
  cin>>h>>w;
  Graph A(h,vector<int>(w,0));
  rep(i,h) rep(j,w) cin>>A[i][j];
  
  Graph ans(1000000);
  int count=0;
  rep(i,h) rep(j,w){
    if(i==h-1 && A[i][j]%2==1){
      if(j!=w-1){
        A[i][j]--;
        A[i][j+1]++;
        ans[count].push_back(i);
        ans[count].push_back(j);
        ans[count].push_back(i);
        ans[count].push_back(j+1);
        count++;
        //cout<<i<<j<<"a"<<endl;
      }
    }
    else if(A[i][j]%2==1){
      if(j!=w-1 && A[i][j+1]%2==1){
        A[i][j]--;
        A[i][j+1]++;
        ans[count].push_back(i);
        ans[count].push_back(j);
        ans[count].push_back(i);
        ans[count].push_back(j+1);
        count++;
        //cout<<i<<j<<"b"<<endl;
      }
      else{
        A[i][j]--;
        A[i+1][j]++;
        ans[count].push_back(i);
        ans[count].push_back(j);
        ans[count].push_back(i+1);
        ans[count].push_back(j);
        count++;
        //cout<<i<<j<<"c"<<endl;
      }
    }
  }
  
  cout<<count<<endl;
  rep(i,count) rep(j,4){
    if(j!=3) cout<<ans[i][j]+1<<" ";
    else cout<<ans[i][j]+1<<endl;
  }
}