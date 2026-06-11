#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  long long ans = 0LL;
  vector<long long> name(5);
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    if(s.at(0) == 'M') name[0]++;
    else if(s.at(0) == 'A') name[1]++;
    else if(s.at(0) == 'R') name[2]++;
    else if(s.at(0) == 'C') name[3]++;
    else if(s.at(0) == 'H') name[4]++;
  }
  for(int i = 0; i < 5; i++){
    for(int j = i + 1; j < 5; j++){
      for(int k = j + 1; k < 5; k++){
        ans += name[i] * name[j] * name[k];
      }
    }
  }
  cout << ans;
}