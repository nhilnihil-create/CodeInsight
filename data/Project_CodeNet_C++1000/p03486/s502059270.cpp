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
    string x,y;
    cin >> x >> y;
	for (int i = 0; i < x.size(); i++) {
		for (int j = i + 1; j <  x.size(); j++) {

			if (x[i] > x[j]) {
				int q = x[i];
				x[i] = x[j];
				x[j] = q;
			}
		}
	}
	for (int i = 0; i < y.size(); i++) {
		for (int j = i + 1; j < y.size(); j++) {

			if (y[i]<y[j]) {
				int q = y[i];
				y[i] = y[j];
				y[j] = q;
			}
		}
	}
	int e = max(x.size(), y.size());
	for (int i = 0; i < e; i++) {
		if (x[i] < y[i]) {
			cout << "Yes";
			break;
		}
		else if (x[i] > y[i]) {
			cout << "No";
			break;
		}
		else if (x[i] == y[i]&&i==e-1) {
			cout << "No";
			break;
		}
		else
			continue;
	}

	

    return 0;
}