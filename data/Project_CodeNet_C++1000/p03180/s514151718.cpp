#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int mxn = 17;
ll a[mxn][mxn], dp[(1<<17)];
vector<int> mask_of_k_bits[mxn];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin>>N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) cin>>a[i][j];

	for(int i=1; i<(1<<N); i++) {
		vector<int> taken;
		for(int j=0; j<N; j++)
			if(i&(1<<j)) taken.push_back(j);
		for(int j=0; j<(int) taken.size(); j++)
			for(int k = j+1; k<(int) taken.size(); k++)
				dp[i]+=a[taken[j]][taken[k]];
	}

	for(int i=1; i<(1<<N); i++) {
		int cnt = 0;
		for(int j=0; j<N; j++)
			if(i&(1<<j)) cnt++;
		mask_of_k_bits[cnt].push_back(i);
	}

	//k is the number of set bit of the mask
	for(int k=2; k<=N; k++) {
		for(auto mask:mask_of_k_bits[k])
			if(k==2) dp[mask] = max(dp[mask], 0ll); 
			else {
				for(int s=mask; s>0; s=(s-1)&mask)
					dp[mask] = max(dp[mask], dp[s]+dp[mask^s]);
			}
	}

	cout << dp[(1<<N)-1] << '\n';
	return 0;

}