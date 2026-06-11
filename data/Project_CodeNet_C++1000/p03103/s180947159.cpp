#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  int N, M;
  cin >> N >> M;
  vector<P>A(N);
  
  rep(i,N)cin >> A[i].first >> A[i].second;
  sort(A.begin(),A.end());
  
  ll ans = 0;
  
  rep(i,N){
    //安いのが残っていればそれを買う
    while(A[i].second){
      ans += A[i].first;
      A[i].second--;
      M--;
      //目的の個数Mに達したら終了
      if(M == 0){
        cout << ans << endl;
        return 0;
      }
    }
    
    
  }
}
