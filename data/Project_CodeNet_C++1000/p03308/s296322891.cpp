#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int N,a;
  int max = 0;
  int min = 999999999;
  cin >> N;
  for(int i=0;i<N;++i){
    cin >> a;
    if(max < a) max = a;
    if(min > a) min = a;
  }
  cout << max - min <<endl;
}