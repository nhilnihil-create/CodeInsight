#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N;
  vector<string> strN(N);
  for (int i=0; i<N; i++) cin >> strN.at(i);
  cin >> M;
  vector<string> strM(M);
  for (int i=0; i<M; i++)  cin >> strM.at(i); 

  int ans = 0;
  map<string, int> table;
  for (int i=0; i<N; i++) table[strN.at(i)]++;
  for (int i=0; i<M; i++) table[strM.at(i)]--;
    
  auto bg = table.begin(), ed = table.end();
  for (auto iter = bg; iter != ed; iter++) {
        // first: key, second: value
//        cout << "key = " << iter->first << "\n";
//        cout << "value = " << iter->second << "\n";
    if(iter->second > ans) ans = iter->second;
    }
  cout << ans << endl;
}