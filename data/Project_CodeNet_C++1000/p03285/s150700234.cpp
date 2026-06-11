#include <iostream>
using namespace std;
int main(){
  int N; cin >> N;
  if(N < 4){
    cout << "No" << endl;
    return 0;
  }
  for(int i = 0; i <= N;i+=4){
    for(int j = 0; j <= N; j+=7){
      if(i + j == N){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}