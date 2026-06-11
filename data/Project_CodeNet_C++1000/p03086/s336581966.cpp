#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  string S;
  cin >> S;
  int ans = 0;
  int count = 0;
  int gg = 0;
   
  rep(i,S.size()){
      if(S.at(i) == 'A' || S.at(i) == 'C' ||  S.at(i) == 'G' ||  S.at(i) == 'T'){
        ans++;
        if(count <= ans){
            count = ans;
            gg = ans;
        }
      }else{
        ans = 0;
      }
  }
  if(gg == 0){
      cout << 0 << endl;
  }else{
      cout << gg << endl;
  }

}