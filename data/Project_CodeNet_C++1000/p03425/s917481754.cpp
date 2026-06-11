#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<char, int> name;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    char c = s.at(0);
    name[c]++;
  }
  
  long long ans = 0;
  vector<long long> cnt(5);
  for(auto now : name){
    char c = now.first;
    long long k = (long long) now.second;
    if(c == 'M') cnt.at(0) = k;
    if(c == 'A') cnt.at(1) = k;
    if(c == 'R') cnt.at(2) = k;
    if(c == 'C') cnt.at(3) = k;
    if(c == 'H') cnt.at(4) = k;
  }
  for(int i = 0; i < 5; i++){
    for(int j = i+1; j < 5; j++){
      for(int k = j+1; k < 5; k++){
        ans += cnt.at(i) * cnt.at(j) * cnt.at(k);
      }
    }
  }
  
  cout << ans << endl;
}