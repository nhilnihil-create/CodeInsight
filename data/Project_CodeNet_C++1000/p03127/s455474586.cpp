// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int a, g;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i) {
            g = gcd(g, a);
        } else {
            g = a;
        }
    }
	cout << g << endl;
	return 0;
}
