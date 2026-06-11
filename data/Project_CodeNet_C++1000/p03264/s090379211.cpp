#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
	int k;
	cin >>k;
	int count =0;
	int count2 =0;
	for (int i =1; i <=k; i++) {
		if (i %2 ==0) count++;
		else count2++;
	}
	cout << count * count2 << endl;
	return 0;
}
