#include <iostream>
#include <string>
using namespace std;
int main(){
  string S,T;
  cin >> S >> T;
  for(int i = 0; i < 3; i++){
    if(S[i] != T[2-i]){
	  cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}