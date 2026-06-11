#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;
  
  for(int x = 0; x*10000 <= Y; ++x) {
    for(int y = 0; y*5000 <= Y; ++y) {
      int r = Y - 10000*x - 5000*y;
      if(0 <= r && r%1000 == 0 && x+y+r/1000 == N) {
        cout << x << " " << y << " " << r/1000 << endl;
        return 0;
      }
    }
  }
     
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}