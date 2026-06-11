#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<typeinfo>
#include<queue>
#include<iomanip>
using namespace std;
int main() {
	long long int X,Y;
	cin >> X>>Y; 
	long long int val=X;
	int count = 0;
	while (val <= Y) {
		val = val * 2;
		count++;
	}
	cout << count;
}
