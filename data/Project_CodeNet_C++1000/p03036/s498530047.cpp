#include <iostream>
#include <vector>
using namespace std;

int main() {
  int r=2;
  int D=10;
  int X=20;
  cin >> r;
  cin >> D;
  cin >> X;
  for(int i=0;i<10;i++){
    X=r*X-D;
    cout << X << endl;
  }
	return 0;
}
