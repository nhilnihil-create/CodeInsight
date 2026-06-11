#include <iostream>
using namespace std;

int main() {
	int a,b,t;
  int ans = 0;
  cin >> a >> b >> t;
  for(int i = a;10*i < 10*t+5;i+=a){
	ans += b;
  }
  cout << ans;
}