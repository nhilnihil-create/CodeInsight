#include<iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int cnt = 0;
  for (int i = 0; i < 4; i++){
    if (S[i] == '2') {
      cnt++;
    }
  }
  cout << cnt << endl;
}