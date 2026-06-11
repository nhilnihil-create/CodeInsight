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
    int max = *max_element(l.begin(), l.end());
    int index = distance(l.begin(), max_element(l.begin(), l.end()));

    int sum_len = 0;
    for(int i =0,end = l.size();i < end; ++i){
      if (i != index){
        sum_len += l.at(i);
        if (sum_len > max) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }

      cout << "No" << endl;
    
    return 0;
}
