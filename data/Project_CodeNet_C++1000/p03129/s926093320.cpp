#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (!(k * 2 - 1 <= n)) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}