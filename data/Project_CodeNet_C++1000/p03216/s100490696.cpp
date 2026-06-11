#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;
int main() {
	int N, Q;
	string S;
	cin >> N >> S >> Q;
	vector<int> k(Q);
	vector<long long> cnt(Q);
	for (int i = 0; i < Q; i++)
		cin >> k[i];
	for (int i = 0; i < Q; i++) {
		long long cntD = 0;
		long long cntM = 0;
		long long cntMD = 0;
		int start = 0;
		for (int j = 0; j < N; j++) {
			if (j - start >= k[i]) {
				if (S[start] == 'D') {
					cntD--;
					cntMD -= cntM;
				}				
				if (S[start] == 'M') {
					cntM--;
					
				}
				start++;
			}
			if (S[j] == 'D')
				cntD++;
			if (S[j] == 'M') {
				cntM++;
				cntMD += cntD;
			}
			if (S[j] == 'C')
			{
				cnt[i] += cntMD;
			}
		}
	}
	for (int i = 0; i < Q; i++)
		cout << cnt[i] << endl;
	return 0;

}