#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  string s;
  int k;
  vector<string>data(0);
  cin >> s >> k;
  rep(i,s.size()){
    string sub = {s[i]};
    data.push_back(sub);
    for(int j = 1;j < k;j++){
      if(i+j >= s.size()) break;
      sub = sub+s[i+j];
      data.push_back(sub);
    }
  }
  sort(data.begin(),data.end());
  unique(data.begin(),data.end());
  cout << data[k-1] << endl;
}