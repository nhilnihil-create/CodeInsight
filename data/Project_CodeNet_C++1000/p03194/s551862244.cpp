#include <iostream> 
#include <vector>
#include <stdio.h>
#include <cmath>
#include <map> 
#include <climits>
#include <unordered_map> 
#include <string> 
#include <algorithm>
#include <stack>
#include <queue>
#include <list> 

using namespace std;

int main() {
	int n;
	long p;
	cin >> n >> p;
	if (n == 1) {
		cout << p << endl;
		return 0;
	}
	long tempP = p;
	int tempCounter = 0;
	int result = 1;
	while (tempP % 2 == 0) {
		tempCounter++;
		tempP /= 2;
	}
	result *= pow(2, floor(tempCounter / n));
	for (int i = 3; i <= sqrt(p); i+= 2) {
		tempCounter = 0;
		while (tempP % i == 0) {
			tempCounter++;
			tempP /= i;
		}
		result *= pow(i, floor(tempCounter / n));
	}
	if (tempP > 2) {
		result *= pow(tempP, floor(tempCounter / n));
	}
	cout << result << endl;
    return 0;
}