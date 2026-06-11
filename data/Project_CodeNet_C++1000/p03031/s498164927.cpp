#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  for(int i=0;i<m;i++){
    int k;
    cin >> k;
    s.at(i) = vector<int>(k);
    for(int j=0;j<k;j++){
      cin >> s.at(i).at(j);
    }
  }
  vector<int> p(m);
  for(int i=0;i<m;i++){
    cin >> p.at(i);
  }
  int count = 0;
  for(int i=0;i<(1 << n);i++){
    bitset<10> b(i);
    bool flag = true;
    for(int j=0;j<m;j++){
      int count1 = 0;
      for(auto a:s.at(j)){
        if(b.test(a-1)){
          count1++;
        }
      }
      if(count1 %2 != p.at(j)){
        flag = false;
        break;
      }
    }
    if(flag){
      count++;
    }
  }
  cout << count << endl;
}