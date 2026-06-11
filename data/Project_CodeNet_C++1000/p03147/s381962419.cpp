#include <iostream>

using namespace std;
int main(){
  int N, h[100], count = 0, k;
  cin >> N;
  for(int i = 0; i<N; i++){
    cin >> h[i];
  }
  
  for(int j = 0; j<N; j++){
    while(h[j] > 0){
      count++;
      k = j;
      while(h[k] > 0 && k < N){
        h[k]--;
        k++;
      }
    }  
  }
  cout << count << endl;
  
  return 0;
}
