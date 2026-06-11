#include <bits/stdc++.h>
using namespace std;
int main(){
  long N, K=0, i=2; cin >> N;
  if(N==0){ cout << "0\n"; return 0; }
  else if(N>0){ while(i<=N){ if(N&i){ N+=i; K+=i; } i<<=2; } }
  else{ i=1; N=-N; while(i<=N){ if(N&i){ N+=i; K+=i; } i<<=2; } }
  i=1; N+=K; string S;
  while(i<=N){ S+=(N&i)?"1":"0"; i<<=1; }
  for(i=S.size()-1; i>=0; i--){ cout << S[i]; }
  cout << "\n";
}