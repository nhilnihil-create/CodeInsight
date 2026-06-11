#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i=0; i<N; i++) cin >> d.at(i);
  
  int ans=N;
  for (int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      if (d.at(i)==d.at(j)){
        ans--;
        break;
      }
    }
  }
  cout << ans << endl;
}