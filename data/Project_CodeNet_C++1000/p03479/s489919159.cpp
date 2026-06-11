#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  long long x;
  long long y;

  cin >> x >> y;

  int counter = 1;
  long long tmp = x;

  while(1){
    tmp = tmp * 2;
    if(tmp > y) break;
    else counter ++;
  }

  cout << counter << endl;

  return 0;
}