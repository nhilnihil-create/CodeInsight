#include <bits/stdc++.h>
using namespace std;
 
long long X, Y, Z, K, A[1009], B[1009], C[1009];
vector<long long>vec;
 
int main() {
	cin >> X >> Y >> Z >> K;
	for (int i = 0; i < X; i++) cin >> A[i]; sort(A, A + X, greater<long long>());
	for (int i = 0; i < Y; i++) cin >> B[i]; sort(B, B + Y, greater<long long>());
	for (int i = 0; i < Z; i++) cin >> C[i]; sort(C, C + Z, greater<long long>());
	
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			for (int k = 0; k < Z; k++) {
				if ((i + 1) * (j + 1) * (k + 1) <= K) vec.push_back(A[i] + B[j] + C[k]);
				else break;
			}
		}
	}
	sort(vec.begin(), vec.end(), greater<long long>());
	for (int i = 0; i < K; i++) cout << vec[i] << endl;
	return 0;
}
