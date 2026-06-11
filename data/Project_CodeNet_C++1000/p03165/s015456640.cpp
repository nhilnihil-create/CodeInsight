#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define Mod 1000000007
using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    // return in;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}
vector<vector<ll> > dp;
string s1,s2;
ll solve(int n, int m)
{
	if(n<0 || m<0)
		return 0;
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(s1[n]==s2[m])
		dp[n][m] = 1+solve(n-1,m-1);
	dp[n][m] = max(dp[n][m],max(solve(n-1,m),solve(n,m-1)));
	return dp[n][m];
}
string getLCS()
{
	int n=s1.length()-1, m=s2.length()-1;
	string ans="";
	while(true)
	{
		while(m>0 && dp[n][m]==dp[n][m-1])
			m--;
		while(n>0 && dp[n][m]==dp[n-1][m])
			n--;	
		if(n<0 || m<0)
			break;
		if(s1[n]==s2[m])
			ans+=s1[n];
		n--;
		m--;
		if(n<0 || m<0)
			break;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()	
{
	#ifdef SANS
		freopen("ongoingin.txt","r",stdin);
		freopen("ongoingout.txt","w",stdout);
	#endif
	fast
	int t=1;
	// cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		dp.resize(s1.length());
		for(int i=0; i<s1.length(); i++)
		{
			dp[i].resize(s2.length()+1,-1);
		}
		ll len = solve(s1.length()-1,s2.length()-1); 
		if(len==0)
			cout<<""<<endl;
		else
			cout<<getLCS()<<endl;
	}
	#ifdef SANS
		cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
	#endif
}