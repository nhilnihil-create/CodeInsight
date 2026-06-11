#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <stack>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
const int mxn = 310;
char matrix[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin>>n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>matrix[i][j];

	int ans = 0, A = 0;
	for(int B=0; B<n; B++) {
		bool good = 1;
		for(int i=0; i<n; i++) {
			for(int j=i; j<n; j++) {
				if(matrix[(i+A)%n][(j+B)%n]!=matrix[(j+A)%n][(i+B)%n]) {
					good = 0; break;
				}
			}
			if(good==0) break;
		}
		ans+=good;
	}

	cout << ans*n << '\n';


	return 0;
}
//comparator function in sorting
//swapping arguments
//missing cases in dp
//dividing in modulo
//Beware of overflow and modulo
//Be mindful of overflow
//s is a matrix but forget
//length of ranges
//working with bit using ull