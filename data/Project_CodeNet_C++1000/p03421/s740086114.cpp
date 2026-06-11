#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,a,b;
	cin >> n >> a >> b;
	if(a > n || b > n) {
		cout << -1;
		return 0;
	}
	if(a+b-1 > n) {
		cout << -1;
		return 0;
	}
	if((n+a-1)/a > b) {
		cout << -1;
		return 0;
	}
	vector<int> res(n);
	int low = 1;
	int tempN = n;
	while(n-tempN + (tempN+a-1)/a < b) {
		res[tempN-1] = low++;
		--tempN;
	}

	int mnUsed = n+1;
	int pos = 0;
	//cout << "mnUsed: " << mnUsed << endl;
	for(int i = 0; i < tempN; i += a) {
		int len = min(a,tempN-i);
		int startVal = mnUsed - len;
		mnUsed -= len;
		for(int j = i; j < i+a && j < tempN; ++j) {
			res[j] = startVal++;
		}
	}



	for(int val : res) cout << val << " ";
	cout << endl;
}
