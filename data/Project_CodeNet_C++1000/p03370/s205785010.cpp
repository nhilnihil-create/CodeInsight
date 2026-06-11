#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
	int x, y,a[101],z=0;
	cin >> x>>y;
	for (int i = 0; i < x; i++) {
		cin >> a[i];
		z += a[i];
	}
	for (int i = 0; i < x; i++) {
		for (int j =i; j < x; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	cout << ((y - z) / a[0]) + x;
}