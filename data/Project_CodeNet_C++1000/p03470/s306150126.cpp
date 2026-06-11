#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int d[110];
  for(int i = 0; i < N; i++){
    cin >> d[i];
  }
  
  int n[110] = {0};
  for(int i = 0; i < N; i++){
    n[d[i]]++;
  }
  
  int count = 0;
  for(int i = 1; i <= 100; i++){
    if(n[i] > 0){
      count++;
    }
  }
  
  cout << count << endl;
}
