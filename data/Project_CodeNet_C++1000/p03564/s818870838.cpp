#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n, k,x=1;
	cin >> n >> k;
	rep(i, n) {
		if (x * 2 <= x + k) {
			x = x * 2;
		}
		else
			x += k;
		
	}
	cout << x << endl;
	return 0;
}