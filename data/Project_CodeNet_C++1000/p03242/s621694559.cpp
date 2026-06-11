#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  string S;
  cin >> S;
  size_t n = S.size();
  for(int i = 0; i< n; i++){
    if(S[i] == '1'){
      S[i] = '9';
    }else if(S[i] == '9'){
      S[i] = '1';
    }else{
      continue;
    }
  }
  cout << S << endl;
  return 0;
}
