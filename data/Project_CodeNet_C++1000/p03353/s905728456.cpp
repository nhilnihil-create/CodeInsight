#include<bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int K; cin >> K;
  vector<string> vec;
  int N = s.size();
  for(int i = 1; i <= 5; i++){
    for(int j = 0; j + i <= N; j++){
      vec.push_back(s.substr(j, i));
    }
  }
  sort(vec.begin(), vec.end());
  int counter = 1;
  if(K == 1){
    cout << vec[0] << endl;
    return 0;
  }
  for(int i = 1; i < vec.size(); i++){
    if(vec[i] != vec[i - 1]) counter++;
    if(counter == K){
      cout << vec[i] << endl;
      return 0;
    }
  }
}