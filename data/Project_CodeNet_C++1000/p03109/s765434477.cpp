#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c;
	char t;
	cin >> a >> t >> b >> t >> c;
	if(a>2019||(a==2019&&b>4)||(b==4&&a==2019&&c>30)) puts("TBD");
	else puts("Heisei");
	return 0;
}