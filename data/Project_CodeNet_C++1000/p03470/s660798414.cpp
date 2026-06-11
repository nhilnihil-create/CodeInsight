#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  vector<int> d(N);
  for(int i=0; i<N; i++){
    cin >> d.at(i);
  }
  
  sort(d.begin(), d.end());
  
  int ans=0;
  int t=0;
  for(int i=0; i<N; i++){
    if(t < d.at(i)){
      t = d.at(i);
      ans++;
    }
  }
  
  cout << ans << endl;
  
}
