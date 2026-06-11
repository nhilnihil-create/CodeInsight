#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, M;
  cin >> N;
  vector<int> D(N);
  for(int i = 0 ; i < N ; i++){
    cin >> D[i];
  }
  cin >> M;
  vector<int> T(M);
  for(int i = 0 ; i < M ; i++){
    cin >> T[i];
  }
  sort(D.begin(),D.end());
  sort(T.begin(),T.end());
  string ans = "YES";
  if(N < M){
    ans = "NO";
  }else{
    int cnt = 0;
    for(int i = 0; i < M ; i++){
      if(T[i] == D[cnt]){

          //cout << "cnt is " << cnt << "T[i] is " << T[i] << "D[cnt] is " << D[cnt] << endl;

          cnt++;
          continue;
      }else if(T[i] > D[cnt]){
        cnt++;
        i--;
      }else{
        ans = "NO";
      }
    }
  }
  cout << ans << endl;
}
