#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

int numberSize(string N) {
	int sum = 0;
	for (int i = 0; i < (int)N.size(); i++) {
		sum += N[i] - '0';
	}
	return sum;
}

int main() {
	string N; cin >> N;
	int sum = numberSize(N);
	int Max = N[0] - '0' + 9 * ((int)N.size() - 1);
	if (sum == Max) cout << sum << endl;
	else cout << Max - 1 << endl;
}
