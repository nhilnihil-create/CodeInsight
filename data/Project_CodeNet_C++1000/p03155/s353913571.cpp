#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main() {
	int N, A, B;
	cin >> N >> A >> B;
	cout << (N - A + 1)*(N - B + 1);
}
