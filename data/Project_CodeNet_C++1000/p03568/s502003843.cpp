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
#include<functional>

using namespace std;
typedef long long ll;



int main() {
	int n; cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) cnt++;
	}
	cout << pow(3,(int)a.size()) - pow(2,cnt) << endl;
}
