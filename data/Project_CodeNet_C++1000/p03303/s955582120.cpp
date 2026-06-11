#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  int w;
  string S;
  cin >> S;
  cin >> w;
  
  int len = S.size();
  for(int i = 0; i < (len + w - 1)/w; i++){
    cout << S.at(w * i);
  }
  cout << endl;
  
}