#include <iostream>
using namespace std;

int main(){
  int N;
  int d[101];
  bool S = true;
  int count = 0;
  
  cin >> N;
  for(int i = 0; i < N; i++) cin >> d[i];
  for(int j = 0; j < N; j++){
    for(int k = j+1; k < N; k++){
      if(d[j] == d[k]) S = false;
    }
    if(S == true) ++count;
    S = true;
  }
  cout << count << endl;
}
