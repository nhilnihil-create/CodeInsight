#include <iostream>
using namespace std;
int main(void){
  int N;
  cin >> N;
  string S = "Three";
  
  for(int i=0; i<N; i++){
    string X;
    cin >> X;
    if(X=="Y"){
      S = "Four";
      break;
    }
  }
  cout << S << endl;
}
