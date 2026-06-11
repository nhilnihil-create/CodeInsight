#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	bool b[1000005] = {false};
	
	int count = 1;
	int k;
	cin >> k;
	
	while (!b[k]) {
		b[k] = true;
		if (k % 2 == 0) {
			k /= 2;
		} else {
			k = 3*k + 1;
		}
		count++;
	}
	
	cout << count << endl;
  return 0;
}