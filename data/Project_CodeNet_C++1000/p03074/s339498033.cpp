#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	int ans = 0;
	int r = 0;
	int cnt = 0;
	if (S[r]=='0'){
		cnt++;
	}
	for (int l = 0; l < N; ++l){
		//cntがKより大きくなるまで右端を動かす
		while( (cnt <= K) && (r < N-1) ) {
			if ( (S[r]=='1') && (S[r+1]=='0') ){
				cnt++;
			}
			if (cnt > K) break;
			r++;
			if (r==N-1) break;
		}
		int tmp = r - l + 1;
		ans = max(ans, tmp);

		// printf("tmp=%i, ans=%i at (l,r)=(%i,%i)\n", tmp, ans, l, r);

		if (l < N-1){
			if ( (S[l]=='0') && (S[l+1]=='1') ){
				// printf("cnt %i -> ", cnt);
				cnt--;
				if (r < N-1){
					r++;
				}
				// printf("%i\n", cnt);
			}
		}
	}

	cout << ans << "\n";


	return 0;
}
