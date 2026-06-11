#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, Z, W;
  cin >> N >> Z >> W;
  
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  
  int score = abs(a[N - 1] - W);
  if(N >= 2) score = max(abs(a[N - 2] - a[N - 1]), score);
  
  cout << score << endl;
  
  return 0;
}