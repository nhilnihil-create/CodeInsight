#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  unordered_map<string, int> left[N + 1];
  multiset<string> right[N + 1];
  
  for(int b = 0; b < (1 << N); b++){
    string front = "", back = "";
    int c = 0;
    for(int i = 0; i < N; i++){
      if(b & (1 << i)){
        front += S[i];
        c++;
      }
      else back = S[i] + back;
    }
    left[c][front + back]++;
  }
  
  for(int b = 0; b < (1 << N); b++){
    string front = "", back = "";
    int c = 0;
    for(int i = N; i < (N << 1); i++){
      if(b & (1 << (i - N))) back += S[i];
      else{
        front = S[i] + front;
        c++;
      }
    }
    right[c].insert(front + back);
  }
  
  long long num = 0;
  for(int c = 0; c <= N; c++){
    for(auto p : left[c]){
      num += p.second * right[c].count(p.first);
    }
  }
  
  cout << num << endl;
  
  return 0;
}