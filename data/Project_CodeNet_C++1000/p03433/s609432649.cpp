#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, a;
	cin >> n >> a;

	int amari = n / 500;
  	if(n % 500 <= a) {
    	cout << "Yes" << endl;
    	return 0;
    } 
	cout << "No" << endl;
}
