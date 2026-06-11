#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M; cin >> N >> M;
  int min = 0, max = 999999999;
  for(int i = 0; i < M; i++){
    int L,R; cin >> L >> R;
    if(min < L) min = L;
    if(max > R) max = R;
  }
  if(max - min + 1 > 0)
  	cout << max - min + 1 << endl;
  else
    cout << 0 << endl;
}