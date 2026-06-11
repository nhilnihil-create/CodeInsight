#include <iostream>
using namespace std;
int main(){
	double a, b;
	cin >> a >> b;
	
	double num = (a + b) / 2.0;
	int ans = (a + b) / 2;
	
	if(num - ans != 0){
		ans++;
	}
	cout << ans << endl;
}