#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M,C;
  cin >> N >> M >> C;
  vector<int> b(M);
  int ans = 0;
  for(int i = 0; i < M; i++){
    cin >> b[i];
  }
  for(int i = 0; i < N; i++){
    vector<int> a(M);
    int sum = 0;
    for(int i = 0; i < M; i++){
      cin >> a[i];
      sum += a[i] * b[i];
    }
    if(sum + C > 0){
      ans++;
    }
  }
  cout << ans << endl;
}