#include <iostream>
using namespace std;

int main() {
  int N,T,c,t,mini=10000;
  cin >> N >> T;
    for(int i = 0; i < N; i += 1){
      cin >> c >> t;
      if(t <= T && c  < mini){
        mini = c;
      }
    }
  if(mini == 10000){
    cout << "TLE" << endl;
  }else{
    cout << mini << endl;
  }
  return 0;
}