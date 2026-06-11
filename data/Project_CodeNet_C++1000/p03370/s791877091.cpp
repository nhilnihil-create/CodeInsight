#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int N,max;
  cin >> N >> max;
  int min = 99999;
  int sum = 0;
  int count = 0;
  for(int i = 0;i < N ;i++){
    int a; 
    cin >> a;
    sum += a;
    if(min > a) min = a;
  }
  count = N;
  max -= sum;
  while(max > 0){
    max -= min;
    if(max < 0) break;
    ++count;
  }
  cout << count << endl;
}