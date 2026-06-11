#include <iostream>
using namespace std;

int main(){
	long long a, b, c, k;
	cin >> a >> b >> c >> k;
	if(abs(a - b) > 1e18) cout << "Unfair" << endl;
	else{
    if(k % 2 == 1) cout << b - a << endl;
    else cout << a - b << endl; 
  }
}