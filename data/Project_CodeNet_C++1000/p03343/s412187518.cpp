#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector <int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int ans = MOD;
	for (int i = 0; i < n; i++) {
		vector <int> cont;
		int last = -1;
		for (int j = 0; j < n; j++) {
			if(A[j] < A[i] || j == n - 1) {
				int ed = (j == n - 1 && A[j] >= A[i]);
				vector <int> v;
				for (int el = last + 1; el <= j - 1 + ed; el++)
					v.push_back(A[el]);
				sort(all(v));
				for (int el = 0; el < (int) v.size() - k + 1; el++)
					cont.push_back(v[el]);
				last = j;
			} 
		}
		
		sort(all(cont));
		if((int) cont.size() >= q)
			ans = min(ans, cont[q - 1] - cont[0]);
	}
	cout << ans;
}
