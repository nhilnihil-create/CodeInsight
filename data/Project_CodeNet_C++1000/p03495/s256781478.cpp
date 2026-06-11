#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> bkt(N,0);
  
  for (int i=0; i<N; i++){
    int a;
    cin >> a;
    bkt.at(a-1)++;
  }
  for (int i=0; i<N; i++){
//    cout << bkt.at(i) << "-";
  }
  sort(bkt.begin(), bkt.end());
  int bcount =0;
  
  for (int i=0; i<N; i++){
//    cout << bkt.at(i) << "-";
    if(bkt.at(i) != 0) bcount++;
  }
//  cout << endl;
//  cout << bcount << endl;
  int ans = 0;
  if (bcount <= K){
    cout << ans <<endl;
    return 0;
  }
  
  for (int i=0; i<N; i++) {
    if(bkt.at(i) != 0){
      ans += bkt.at(i);
      bcount--;
    }
    if (bcount == K) break;
  }
  
  
  cout << ans << endl;
  return 0;
}