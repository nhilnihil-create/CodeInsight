#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
  int Bob = 0;
  int Alice = 0;
  int cal = 0;
  int N;
  int a[100];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a, a + N, greater<int>());
  for (int i = 0; i < N; i++) {
    if(i%2 == 0){
      Alice += a[i];
    }
    else{
      Bob += a[i];
    }
  }
  cal = Alice - Bob;
  cout << cal;
}
