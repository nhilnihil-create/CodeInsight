#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1010;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
int arr[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
	int n, m;
	cin>>n>>m;
	unordered_map<int, int> mp;
	rep(i, 0, m)
	{
		int x;
		cin>>x;
		chmax(mp[arr[x-1]], x);
	}
	vector<int> dp(n+1);
	vector<int> track(n+1, -1);
	vector<int> label(n+1, 0);
	dp[0] = track[0] = 0;
	repn(i, 1, n)
	{
		for(auto x: mp)
		{
			int cost = x.f;
			int val = x.s;
			if(i - cost >= 0 && track[i - cost] != -1)
			{
				if(dp[i] < dp[i-cost] + 1)
				{
					dp[i] = dp[i-cost] + 1;
					track[i] = i-cost;
					label[i] = val;
				}
				if(dp[i] == dp[i-cost]+1)
				{
					if(label[i] < val)
					{
						label[i] = val;
						track[i] = i - cost;
					}
				}
			}
		}
	}
	int i = n;
	string ans = "";
	while(i != 0)
	{
		ans += to_string(label[i]);
		i = track[i];
	} 
	sort(ans.rbegin(), ans.rend());
	cout<<ans<<endl;

}
