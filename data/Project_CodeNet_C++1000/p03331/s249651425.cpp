#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;

int calc( int num) {
	int count1 = 0;
	while (num > 0) {
		count1 = count1 + num % 10;
		num = num / 10;
	}

	return count1;
}


int main(){
	int n;
	cin >> n;

	int count = 1000000;

	for (int i = 1; i <n ;i++) {
		
		int a = n - i;
		int count1 = 0;
		
		count1 = calc(i)+calc(a);
		
		if (count > count1)count = count1;

	}

	cout << count << endl;

	return 0;

}