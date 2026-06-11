#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

const int mod = 1e9+7;


int main() {
	int n;
	scanf("%d", &n);

	long long a[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	const int dp_size = (1<<n);

	int num_bits[dp_size];
	vector<int> masks[n+1];
	num_bits[0] = 0;
	masks[0].push_back(0);
	for(int i=1; i<dp_size; i++) {
		num_bits[i] = num_bits[i>>1]+(i&1);
		masks[num_bits[i]].push_back(i);
	}

	long long mask_value[dp_size];
	memset(mask_value, 0, sizeof mask_value);
	for(int set_bits=2; set_bits<=n; set_bits++) {
		for(auto mask: masks[set_bits]) {
			int first;
			for(int i=0; i<n; i++) {
				if(mask&(1<<i)) {
					first = i;
					break;
				}
			}
			int pre_mask = mask^(1<<first);
			long long add_val = 0;
			for(int i=0; i<n; i++) {
				if(pre_mask&(1<<i)) {
					add_val += a[first][i];
				}
			}
			mask_value[mask] = mask_value[pre_mask] + add_val;
		}
	}

	long long dp[dp_size];
	memset(dp, 0, sizeof dp);
	for(int set_bits=n-1; set_bits>=0; set_bits--) {
		for(auto set_mask: masks[set_bits]) {
			for(int mask = (set_mask+1)|set_mask; mask<dp_size; mask = (mask+1)|set_mask ) {
				int diff_mask = mask^set_mask;
				dp[set_mask] = max(dp[set_mask], dp[mask] + mask_value[diff_mask]);
			}
		}
	}
	printf("%lld\n", dp[0]);
    return 0;
}