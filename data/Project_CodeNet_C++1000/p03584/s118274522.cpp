#include <iostream>
using namespace std;

int main(){
	int64_t n, k;
	cin >> n >> k;
	int64_t a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	bool puni[32]{};
	for(int i = 0; i < 32; i++){
		puni[i] = (k >> i) & 1;
	}
	int64_t ans = 0;
	for(int i = 0; i < 32; i++){
		if(puni[i]){
			bool muni[32];
			for(int j = 0; j < 32; j++){
				if(i == j) muni[j] = false;
				if(i < j) muni[j] = puni[j];
				if(j < i) muni[j] = true;
			}
			int64_t score = 0;
			for(int j = 0; j < n; j++){
				bool f = true;
				for(int k = 0; k < 32; k++){
					if(!muni[k]){
						f &= !((a[j] >> k) & 1);
					}
				}
				if(f) score += b[j];
			}
			ans = max(ans, score);
		}
	}
	{
		int64_t score = 0;
		for(int i = 0; i < n; i++){
			bool f = true;
			for(int j = 0; j < 32; j++){
				if(!puni[j]){
					f &= !((a[i] >> j) & 1);
				}
			}
			if(f) score += b[i];
		}
		ans = max(ans, score);
	}
	cout << ans << endl;
	return 0;
}