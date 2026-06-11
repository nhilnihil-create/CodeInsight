#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans[110];
  rep(i,110)ans[i] = 0;
  rep(i,26){
    rep(j,15){
      if(i*4 + j*7 <= 100)ans[i*4+j*7] = 1;
    }
  }
  if(ans[n] == 1)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}