#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll H,W,N=0;
  cin >> H >> W;
  vector<vector<ll>> A(H,vector<ll>(W)),ans(H*W,vector<ll>(4));
  rep(i,H)rep(j,W) cin >> A.at(i).at(j);
  rep(i,H){
    if(i%2==0){
      rep(j,W){
        if(A.at(i).at(j)%2==1){
          A.at(i).at(j)--;
          if(j!=W-1){
            A.at(i).at(j+1)++;
            ans.at(N).at(0)=i+1;
            ans.at(N).at(1)=j+1;
            ans.at(N).at(2)=i+1;
            ans.at(N).at(3)=j+2;
            N++;
          }else if(i!=H-1){
            A.at(i+1).at(j)++;
            ans.at(N).at(0)=i+1;
            ans.at(N).at(1)=j+1;
            ans.at(N).at(2)=i+2;
            ans.at(N).at(3)=j+1;
            N++;
          }
        }
      }
    }else{
      rep(j,W){
        if(A.at(i).at(W-j-1)%2==1){
          A.at(i).at(W-j-1)--;
          if(j!=W-1){
            A.at(i).at(W-j-2)++;
            ans.at(N).at(0)=i+1;
            ans.at(N).at(1)=W-j;
            ans.at(N).at(2)=i+1;
            ans.at(N).at(3)=W-j-1;
            N++;
          }else if(i!=H-1){
            A.at(i+1).at(W-j-1)++;
            ans.at(N).at(0)=i+1;
            ans.at(N).at(1)=W-j;
            ans.at(N).at(2)=i+2;
            ans.at(N).at(3)=W-j;
            N++;
          }
        }
      }
    }
  }
  cout << N << endl;
  rep(i,N){
    cout << ans.at(i).at(0) << " " << ans.at(i).at(1) << " " << ans.at(i).at(2) << " " << ans.at(i).at(3) << endl;
  }
  

}
