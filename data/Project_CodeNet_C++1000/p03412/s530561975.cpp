#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL N;
	cin >> N;

	vector<LL> A(N),B(N);

	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	for(int i = 0; i < N; i++){
		cin >> B[i];
	}

	LL ibit = 1;
	LL ans = 0;

	for(int i = 0; i < 29; i++){
		ibit <<= 1;
		LL count = 0;
		vector<LL> tmp(N);
		for(int j = 0; j < N; j++){
			tmp[j] = B[j]%ibit;
		}
		sort(tmp.begin(),tmp.end());
		for(int j = 0; j < N; j++){
			LL start;
			if(A[j]%ibit >= ibit >> 1){
				start = 1;
			}else{
				LL skey = (ibit >> 1) - (A[j]%ibit);
				auto sitr = lower_bound(tmp.begin(),tmp.end(),skey);
				start = (LL)(sitr - tmp.begin()) + 1;
			}
			LL key = ibit - (A[j]%ibit);
			auto itr = lower_bound(tmp.begin(),tmp.end(),key);
			LL end = (LL)(itr - tmp.begin())+1;
			LL nkey = ibit + (ibit >> 1) -(A[j]%ibit);
			auto nitr = lower_bound(tmp.begin(),tmp.end(),nkey);
			count += (LL)(tmp.end() - nitr);
			if(end - start >= 0){
				count += end - start;
			}
		}
		if(count % 2 == 0){
		}else{
			ans += (ibit >> 1);
		}
	}

	cout << ans << endl;
    
    return 0;
}