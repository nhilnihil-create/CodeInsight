#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000002




int main(){

	int N;
	cin>>N;
	
	long long A,B;
	cin>>A>>B;
	
	vector<int> P(N);
	for(int i=0;i<N;i++)cin>>P[i];
	P.insert(P.begin(),0);
	P.push_back(N+1);
	
	vector<long long> dp(P.size(),Inf);
	dp[0] = 0LL;
	
	for(int i=1;i<P.size();i++){
		long long t = 0LL;
		for(int j=i-1;j>=0;j--){
			if(P[j]>P[i]){
				t += A;
			}
			else{
				dp[i] = min(dp[i],dp[j]+t);
				t += B;
			}
		}
	}
	cout<<dp.back()<<endl;
	return 0;
}