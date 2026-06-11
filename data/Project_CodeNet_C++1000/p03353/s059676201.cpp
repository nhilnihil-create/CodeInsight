#include<bits/stdc++.h>
using namespace std;


using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  set<string> SET;
  string s;
  int K;
  cin >> s >> K;
  
  for(int i = 0; i<s.size(); i++){
    for(int j = 1; j<=K; j++){
      string t = s.substr(i,j);
      SET.insert(t);
    }
  }
  
  int cnt = 0;
  
  for(auto c : SET){
    cnt++;
    if(cnt==K){
      cout << c << endl;
    }
  }
}      
       



