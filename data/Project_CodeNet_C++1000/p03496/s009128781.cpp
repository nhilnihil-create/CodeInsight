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

bool visited[1005][1005][1005];
 
int main () {
	int N;
    cin >> N;
	vector<ll> v(N);
	rep(i,N) {
		cin >> v[i];
	}
	int max_ind = max_element(v.begin(),v.end()) - v.begin();

	int min_ind = min_element(v.begin(),v.end()) - v.begin();
	if (v[max_ind] < 0) {
		cout << N-1 << endl;
		for (int i = N; i > 1; --i) {
			cout << i << " " << i-1 << endl; 
		}		
	}
	else if (v[min_ind] >= 0) {
		cout << N-1 << endl;
		for (int i = 1; i < N; ++i) {
			cout << i << " " << i+1 << endl; 
		}		
	} else {
		if (abs(v[max_ind]) >= abs(v[min_ind])) {
			cout << 2*N-1 << endl;
			for (int i = 1; i <= N; ++i) {
				cout << max_ind + 1 << " " << i << endl; 
			}	
			for (int i = 1; i < N; ++i) {
				cout << i << " " << i+1 << endl; 
			}	
		} else {
			cout << 2*N-1 << endl;
			for (int i = 1; i <= N; ++i) {
				cout << min_ind + 1 << " " << i << endl; 
			}	
			for (int i = N; i > 1; --i) {
				cout << i << " " << i-1 << endl; 
			}	
		}
	}
    return 0;
}