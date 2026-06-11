#include <iostream>
using namespace std;

string getResult(string S, int w){
  const size_t size = S.size();
  string result = "";
  for(size_t i = 0; i < size; i += w){
    result.push_back(S[i]);
  }
  return result;
}

int main(){
  string S;
  int w;
  cin >> S >> w;
  
  string result = getResult(S, w);  
  cout << result;
}