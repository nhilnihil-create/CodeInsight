#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, M, i, cnt = 1;
  cin >> N >> M;
  vector<pair<int, int>> ILND(M);
  
  for(i = 0; i < M; i++) cin >> ILND[i].second >> ILND[i].first;
  sort(ILND.begin(), ILND.end());
  
  for(i = 0;;){
    
    int G = ILND[i].first, j = 0;
    while(G > ILND[j].second){
      if(j == M - 1){
        cout << cnt << endl;
        return 0;
      }
      j++;
    }
    cout << endl;
    i = j, cnt++;
  }
  return 0;
}