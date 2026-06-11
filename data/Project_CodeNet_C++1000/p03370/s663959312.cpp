#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

int main(void){

  //initialization
  int N,X;
  int m;
  int min = INF;
  int count;


  cin >> N >> X;
  for(int i; i<N; i++){
    cin >> m;
    X -= m;
    if(min > m) min = m;
  }     

  count = N + X / min;  
  cout << count << "\n";
}
