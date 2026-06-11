#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	if(n==0){
		cout<<0<<endl;
		return 0;
	} 
	string ans="";
	while(n!=0){
		if(n%2==0){
			ans+="0";
			n/=(-2);
		}
		else{
			ans+="1";
			if(n<0) n=(n-1)/(-2);
			else n/=(-2);
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}