#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_abc111(void) {
	int n;
	cin >> n;

	int sho = n / 111;
	int amari = n % 111;

	if(amari!=0){
		sho++;
	}

	cout << 111 * sho << endl;
}

int main()
{
    b_abc111();
}