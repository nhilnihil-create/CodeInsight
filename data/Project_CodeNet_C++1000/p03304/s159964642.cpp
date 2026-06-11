#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double n, m, d;
	cin >> n >> m >> d;
	double p = (d == 0 ? 1 : 2) * (n - d) / (n * n);
	cout << fixed << setprecision(15) << p * (m - 1) << endl;
}
