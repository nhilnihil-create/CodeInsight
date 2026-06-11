#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
   
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
   
int main()
{
    string s;
	cin>>s;
	int n=s.size();
	set<P> st;
	st.insert(P(0, 0));
	int dp[200001];
	int a[200001];
	dp[0]=0;
	a[0]=0;
	for(int i=1; i<=n; i++){
		a[i]=a[i-1]^(1<<(s[i-1]-'a'));
		if(a[i]==0){
			dp[i]=1;
			st.insert(P(a[i], i));
			continue;
		}
		dp[i]=dp[i-1]+1;
		for(int j=0; j<26; j++){
			int a0=a[i]^(1<<j);
			if(a0==0){
				dp[i]=1;
				break;
			}
			auto itr=st.upper_bound(P(a0, 1e9));
			itr--;
			if((*itr).first==a0){
				int i0=(*itr).second;
				dp[i]=min(dp[i], dp[i0]+1);
			}
		}
		st.insert(P(a[i], i));
	}
	cout<<dp[n]<<endl;
    return 0;
}