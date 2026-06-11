#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main(){
  int n; cin >> n;
  int kosuu = 0;
  for(int i = 1; i <= n; ++i){
    int yaku = 0;
    if(i%2==1){
      for(int j = 1; j<=i; ++j){
        if(i%j==0) yaku++;
      }
    }
    if(yaku==8) kosuu++;
  }
  cout << kosuu << "\n";
}