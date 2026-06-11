#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	char c;
	cin >> c;
	if(c=='A') c='T';
	else if(c=='T') c='A';
	if(c=='C') c='G';
	else if(c=='G') c='C';
	cout << c;
	return 0;
}