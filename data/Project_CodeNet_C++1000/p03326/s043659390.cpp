#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
long long N, M, a[100009][3],maxn = -(10000000000);

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) cin >> a[i][j];
	}
	for (int i = 0; i < 8; i++) {
		long long b[10000];
		for (int j = 1; j <= N; j++) {
			long long S = 0;
			for (int k = 0; k < 3; k++) { 
                if ((i / (1 << k)) % 2 == 0) 
                    S += a[j][k]; 
                else S -= a[j][k]; 
			}
			b[j] = S;
		}
		sort(b+1,b+N+1); 
		long long ans = 0;
		for (int j = N; j >= N-M+1; j--) 
            ans += b[j];
        cout<<endl;
		maxn = max(maxn, ans);
	}
	cout << maxn << endl;
	return 0;
}