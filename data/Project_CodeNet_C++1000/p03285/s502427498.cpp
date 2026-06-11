#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(void){
  int N; cin >> N;
  bool OK = false;
  for(int i = 0; i <= N / 4; i++){
      for(int j = 0; j <= N / 7; j++){
          if(4 * i + 7 * j == N) OK = true;
      }
  }
  if(OK != true) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}