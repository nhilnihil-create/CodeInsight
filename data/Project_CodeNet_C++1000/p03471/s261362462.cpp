#include <iostream>
using namespace std;

int main() {
  int N, Y;
  int x,y,z,total;
  int resx,resy,resz;
  resx = -1;
  resy = -1;
  resz = -1;
  cin >> N >> Y;
  for(x=0; x<=N; x++){
    for(y=0; x+y<=N; y++){
      z = N-x-y;
      total = x*10000 + y*5000 + z*1000;
      if(total == Y){
        resx = x;
        resy = y;
        resz = z;
      }
    }
  }
  cout << resx << " " << resy << " " << resz << endl;
}
  