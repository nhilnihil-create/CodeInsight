#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c,d,e,k;
	cin >> a >> b >> c >> d >> e >> k;
	if(e-a<=k) puts("Yay!");
	else puts(":(");
	return 0;
}