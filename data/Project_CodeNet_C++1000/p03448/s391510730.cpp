#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i <=(int)(n); ++i)

int main() {
  int X,A,B,C;
  cin >> A >> B >> C >> X;
  
  
  //int size = (A+1)*(B+1)*(C+1);
  //vector<int> ans(size,0);
  //vector<vector<vector<int>>> vec(100, vector<vector<int>>(100, vector<int>(100)));
  int sum = 0;
  int ans = 0; 

  rep(i,A) rep(j,B) rep(k,C){
      sum = 500 * i + 100 * j + 50 * k;
      if(sum == X){
          ans++;
      }
  }

  cout << ans << endl;
  
}
