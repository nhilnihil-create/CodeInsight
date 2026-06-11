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
	int N, K;
    cin >> N >> K;
	vi v(N);
	rep(i,N) {
		cin >> v[i]; 
	}
	int ans = 0;
	for (int a = 0; a<=min(N,K); ++a){
		for (int b = 0; a+b <= min(N,K); ++b){
			vector<int> pq;
			int s = 0;
			rep (i,a) {
				pq.push_back(v[i]);
				s += v[i];
			}
			for (int i = 0; i < b; ++i) {
				pq.push_back(v[N-1-i]);
				s += v[N-1-i];
			}
			sort(pq.begin(), pq.end());
			for (int i = 0; i < min(K - a - b, (int)pq.size()); ++i) {
				if (pq[i] < 0)
					s -= pq[i];
			}
			ans = max(ans,s);
		}
	}
	cout << ans << endl;
    return 0;
}