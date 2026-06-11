 #include <bits/stdc++.h>
// #include <iostream> 
// #include <sstream> 
// #define int unsigned long long int
using namespace std;
 
 
 
// // bool prime[1000001]; 
 
// // void SieveOfEratosthenes(int n) 
// // { 
// //     // Create a boolean array "prime[0..n]" and initialize 
// //     // all entries it as true. A value in prime[i] will 
// //     // finally be false if i is Not a prime, else true. 
    
// //     memset(prime, true, sizeof(prime)); 
  
// //     for (int p=2; p*p<=n; p++) 
// //     { 
// //         // If prime[p] is not changed, then it is a prime 
// //         if (prime[p] == true) 
// //         { 
// //             // Update all multiples of p greater than or  
// //             // equal to the square of it 
// //             // numbers which are multiple of p and are 
// //             // less than p^2 are already been marked.  
// //             for (int i=p*p; i<=n; i += p) 
// //                 prime[i] = false; 
// //         } 
// //     } 
  
// // }

long long int mod = 1000000007;

unordered_map<int,std::vector<int>> grp;

void f(vector<pair<int,int>>& dp, int src, int par){
	bool ch = false;
	long long int w = 1;
	long long int b = 1;

	for(auto dest: grp[src]){
		if(dest==par)continue;
		ch = true;
		f(dp,dest,src);
		long long int cw = dp[dest].first;
		long long int cb = dp[dest].second;
		b = (b* cw%mod)%mod;
		w = (w* (cw+cb)%mod)%mod;
	}

	dp[src].first = w%mod;
	dp[src].second = b%mod;
	return;
}

int main()
{
	 long long int t;

	 long long int mod = 1000000007;
	 t=1;
	for( long long int ts=1; ts<=t; ts++){
		long long int n;
		cin>>n;
		std::vector<pair<int,int>> dp(n);
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			x--;
			y--;
			grp[x].push_back(y);
			grp[y].push_back(x);
		}

		f(dp, 0, -1);
		cout<<((dp[0].first + dp[0].second)%mod)<<endl;
	}
	return 0;
}
 
 
 
 