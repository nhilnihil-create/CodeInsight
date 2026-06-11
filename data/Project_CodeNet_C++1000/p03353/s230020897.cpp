#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  int K;
  cin >> K;
  
  map<string, int> m;
  
  // 長さiの文字列
  for(int i = 1; i <= K; i++){
    string tmp;
    for(int j = 0; j < N && j + i - 1 < N; j++){
      tmp = S.substr(j, i);
      if(m.count(tmp) == 0){
        m[tmp] = 1;
      }
    }
  }
  
  int index = 0;
  for(auto x : m){
    index++;
    // cerr << x.first << " " << x.second << endl;
    if(index == K){
      cout << x.first << endl;
    }
  }

}