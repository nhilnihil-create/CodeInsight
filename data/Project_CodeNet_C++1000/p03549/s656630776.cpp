#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	double N, M; cin >> N >> M;
	cout << ((N - M) * 100.0 + M * 1900.0) / pow(0.5, M) << endl;
}