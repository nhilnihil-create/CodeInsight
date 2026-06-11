#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define dd double
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl '\n'

int n;
vector<vector<vector<dd>>> dp(301,vector<vector<dd>>(301,vector<dd>(301,-1)));

dd sushi(int one,int two,int three){
	if(one<0||two<0||three<0)return 0;
	if(one==0 && two==0 && three==0) return 0;

	if(dp[one][two][three] > 0) return dp[one][two][three];

	int rem=one+two+three;
	dd expval=(n+one*sushi(one-1,two,three)+two*sushi(one+1,two-1,three)+three*sushi(one,two+1,three-1));
	return dp[one][two][three]=(expval/rem);
}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;
	int one=0,two=0,three = 0;

	for0(i,n){
		int x;
		cin >> x;
		if(x==1)one++;
		else if(x==2)two++;
		else three++;
	}

	cout <<setprecision(17)<<sushi(one,two,three);
	
	return 0;
}