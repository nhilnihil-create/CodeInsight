#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<vector<int>> S(100, vector<int> (N));
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		S.at(c - 'a').at(i)++;
	}
	
	int ttl = 0;
	int cntX, cntY;
	for (int i = 1; i < N; i++) {	
		int subttl = 0;
		for (int k = 0; k < 26; k++) {
			cntX = cntY = 0;
			for (int j = 0; j < i; j++) {
				cntX += S.at(k).at(j);
			}
			for (int j = i; j < N; j++) {
				cntY += S.at(k).at(j);
			}
			if (cntX > 0 && cntY > 0) subttl++;
		}
		ttl = max(ttl, subttl);
	}
	cout << ttl << endl;
}