#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;



int main(){
  string S;
  int K;
  cin >> S >> K;
  rep(i, S.size()){
    if(S[i] != '1' || i == K-1){
      cout << S[i] << endl;
      break;
    }
  }
    
}