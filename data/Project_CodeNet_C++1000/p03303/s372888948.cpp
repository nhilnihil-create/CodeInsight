#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>
#include<math.h>

using namespace std;
#define rep(i, n) for ( int i = 0; i < ( int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < ( int)(n); i++)

int main() {
	string s;
	int w;
	cin >> s >> w;
	int n = s.size();
	rep(i, n) {
		if (i % w == 0) cout << s[i];
	}
	cout << endl;
	return 0;

}//mita