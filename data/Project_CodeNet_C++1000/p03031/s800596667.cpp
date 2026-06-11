#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>> s(M);
  for (int i =0; i<M; i++) {
    int k;
    cin >> k;
    for (int j =0; j<k; j++) {
      int x;
      cin >> x;
      s.at(i).push_back(x);
    }
  }
  vector<int> p(M);
  for (int i =0; i<M; i++) {
    cin >> p.at(i);
  }
 
  //ビット全検索
  int count =0;
  for (int tmp = 0; tmp < (1 << 10); tmp++) {
    if (tmp >= pow(2,N)) break;
    bitset<10> bit(tmp);
    int countK =0;
    for (int i =0; i<M; i++) {
      int countS =0;
      for (int j =0; j<s.at(i).size(); j++) {  
        if (bit[s.at(i).at(j)-1] == 1) countS++;
      }
      if (countS % 2 == p.at(i)) countK++;
    }
    if (countK == M) count++;
  }
  cout << count << endl;
}