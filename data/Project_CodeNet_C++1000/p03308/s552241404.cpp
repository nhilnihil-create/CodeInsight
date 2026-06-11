#include<bits/stdc++.h>
#define int long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
#define REP_sz(i,s) for(int i=0;i<s.size();i++)
#define RE return
#define FILL(a,b) memset(a,b,sizeof(a))
#define SO(a) sort(all(a))
#define pb push_back
#define sz(a) a.size()
#define V vector
#define ld long double
#define viit(a) vector<int>::iterator a
#define msit1(a) map<string,int>::iterator a
#define miit(a) map<int,int>::iterator a
#define msit2(a) map<int,string>::iterator a
#define IT iterator
#define FOR(i,a,n) for(int i=a;i<=(n);i++)
#define B(s) s.back()
#define all(a) a.begin(),a.end()
#define ER1(a) a.erase(a.begin())
#define ER0(a) a.erase(a.end())
#define pii pair<int,int>
#define pause system("PAUSE")
#define cls system("CLS")
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	V<int>a(n);
	REP(i,0,n)cin>>a[i];
	SO(a);
	cout<<a[a.size()-1]-a[0];
    return 0;
}
