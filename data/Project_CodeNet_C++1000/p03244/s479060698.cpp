#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;
	int max_n = 100000;
	int even[max_n], odd[max_n];
	rep(i, max_n) even[i]=odd[i]=0;
	rep(i, n/2) {
		int o, e;
		cin >> o >> e;
		odd[o]++;
		even[e]++;
	}
	int even_max = 0, even_max_n = 0;
    int even_second = 0, even_second_n = 0;
    int odd_max = 0, odd_max_n = 0;
    int odd_second = 0, odd_second_n = 0;

    rep(i, max_n) {
    	if (even[i] > even_max) {
    		even_second = even_max;
    		even_second_n = even_max_n;
    		even_max = even[i];
    		even_max_n = i;
    	}
    	else if (even[i] > even_second) {
    		even_second = even[i];
    		even_second_n = i;
    	}
    	if (odd[i] > odd_max) {
    		odd_second = odd_max;
    		odd_second_n = odd_max_n;
    		odd_max = odd[i];
    		odd_max_n = i;
    	}
    	else if (odd[i] > odd_second) {
    		odd_second = odd[i];
    		odd_second_n = i;
    	}
    }
    if (even_max_n != odd_max_n) {
    	cout << n - even_max - odd_max << endl;
    }
    else {
    	cout << min(n - even_max - odd_second, n - even_second - odd_max) << endl;
    }
}