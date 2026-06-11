#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> l(N);
    for (int n = 0; n < N; ++n){
      int t;
      cin >> t;
      l[n] = t;
    }

    int cnt = 0;
    while(*max_element(l.begin(), l.end()) > 0) {
      int max = *max_element(l.begin(), l.end());
      int index = distance(l.begin(), max_element(l.begin(), l.end()));
      l[index] -= 1;
      // 左側
      for(int i = index - 1;i>=0;--i){
        if (l.at(i) < max) break;
        l[i] -= 1;
      }
      // 右側
      for(int i = index + 1;i<l.size();++i){
        if (l.at(i) < max) break;
        l[i] -= 1;
      }

      // for(int i =0;i < l.size();++i) {
      //   cout << l.at(i) << ' ';
      // }
      // cout << endl;
      cnt += 1; 
    }
    cout << cnt << endl;
    return 0;
}
