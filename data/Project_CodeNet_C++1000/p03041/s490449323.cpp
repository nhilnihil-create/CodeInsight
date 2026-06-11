#include <iostream>
#include <vector>
using namespace std;

int N, K;
string S;

int main(){
  cin >> N >> K;
  cin >> S;

  char k = S.at(K-1);

  if( k == 'A'){
    S.at(K-1) = 'a';
  }else if( k == 'B'){
    S.at(K-1) = 'b';
  }else if( k == 'C'){
    S.at(K-1) = 'c';
  }
  
  cout << S << endl;
}
