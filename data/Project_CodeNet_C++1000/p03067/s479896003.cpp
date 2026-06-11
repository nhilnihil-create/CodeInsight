#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c;
	cin >> a >> b >> c;
	if(c<max(a,b)&&c>min(a,b)) puts("Yes");
	else puts("No");
	return 0;
}