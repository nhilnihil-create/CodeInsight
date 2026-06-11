#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
int main () {
	int N, C;
    cin >> N >> C;
	vector<int> S(N), T(N), CN(N);
	vector<int> mx(200002,0), tt(200002,0);
	rep(i,N) {
		cin >> S[i] >> T[i] >> CN[i];
	}
	for (int c = 1; c <= C; ++c) {
		fill(tt.begin(), tt.end(), 0);
		rep(i,N) {
			if (CN[i] == c) {
				tt[2*S[i]-1]++;
				tt[2*T[i]]--;
			}
		}
		for (int i = 1; i < 200002; ++i) {
			tt[i] += tt[i-1];
		}
		for (int i = 0; i < 200002; ++i) {
			if (tt[i] > 0) mx[i]++;
		}
	}
	cout << *max_element(mx.begin(), mx.end()) << endl;
    return 0;
}