#include <iostream>
#include <string.h>
using namespace std;

void a_already2018(void) {
	string s;
	cin >> s;
	s[3] = '8';
	cout << s << endl;
}

int main()
{
	a_already2018();
    return 0;
}