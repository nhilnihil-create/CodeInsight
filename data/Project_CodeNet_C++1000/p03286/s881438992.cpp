#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;cin >> N;
  vector<int> S;
  while(1){
    if(N%2==0){
      S.push_back(0);
    }else{
      S.push_back(1);
      N = N - 1;
    }
    N = N / (-2);
    if(N==0){
      for(int i=S.size()-1;i>=0;i--){
        cout << S[i];
      }
      cout << endl;
      return 0;
    }
  }
}