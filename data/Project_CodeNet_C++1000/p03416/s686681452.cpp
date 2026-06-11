#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main() {
  int S,G;
  cin >> S >> G;
  int res = 0;
  int count = 0;
  for(int i = S; i<=G;i++){
    int N = i;
    res = 0;
    res += (N % 10) * 10;
    N /= 10;
    res  += N % 10;
    N/=10;
    if(res == N /10) ++count;
  }
  cout << count << endl;
}