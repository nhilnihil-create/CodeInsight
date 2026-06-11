#include <iostream>
using namespace std;

long long x, y, bil, ans;
int main() {
	cin >>x>>y;
  	bil =x;
    while (bil<=y){
      ans ++;
      bil=bil*2;
    }
	cout <<ans<<endl;
}
