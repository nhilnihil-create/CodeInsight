#include <iostream>
using namespace std;

int main() {
  int N,i,j;
  cin >> N;
  for(i=0; i<30; i++){
    for(j=0;j<30;j++){
      if(4*i+7*j==N){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}