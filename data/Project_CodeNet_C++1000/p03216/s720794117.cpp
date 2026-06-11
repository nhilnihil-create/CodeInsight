#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n, q;
string s;

void solve(int k)
{
	int ans = 0;
	int i, d = 0, m = 0, l = 0, dm = 0;

	fr(i,0,n)
	{
		if(i - l == k)
		{
			if(s[l] == 'D')  d--, dm-=m;
			if(s[l] == 'M') m--;
			l++;
		}
		if(s[i] == 'C')
		{
			ans += dm;
		}
		if(s[i] == 'D') d++;
		if(s[i] == 'M') m++;
		if(s[i] == 'M') dm += d;
	}
	cout<<ans<<"\n";
}
signed main()
{
 	start_routine
	cin>>n>>s>>q;
	while(q--)
	{
		int k;
		cin>>k;
		solve(k);
	}
 	end_routine
}
