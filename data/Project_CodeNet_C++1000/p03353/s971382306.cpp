#include <bits/stdc++.h>

using namespace std;


int main() {
  string s;
  int K;
  cin >> s >> K;
  
  vector<string> substr;
  
  for(int i=0; i<s.size(); ++i){
    for(int j=1; j<=K; ++j){
      string tmp = s.substr(i, j);
      substr.push_back(tmp);
    }
  }
  
  sort(substr.begin(), substr.end());
  substr.erase(unique(substr.begin(), substr.end()), substr.end());
  
  cout << substr[K-1] << endl;
  
}
