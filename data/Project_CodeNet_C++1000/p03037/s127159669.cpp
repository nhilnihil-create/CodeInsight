#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  long long N, M;   
  cin >> N >> M; 
  int LM = 0, RM = N-1;
  for(int i = 0; i < M; i++){
    int L, R;
    cin >> L >> R;
    L--; R--;
    if(LM < L){
      LM = L;
    }
    if(RM > R){
      RM = R;
    }
  }
  if(RM >= LM){
    cout << RM - LM + 1 <<endl;
  } else{
    cout << 0 <<endl; 
  }
}
