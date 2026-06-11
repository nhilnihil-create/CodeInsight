#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
#define con(x,y)	((x)*(m)+(y))
using namespace std;

void solve()	{
	string s;
	cin >> s;
	int n = s.size();
	string r = "keyence";
	set<string> st;
	for(int i=0; i<n; i++)	{
		if(st.find("keyenc")!=st.end() && s.substr(i,1)=="e" && i==n-1)	{
			cout << "YES\n";
			return;
		}
		if(st.find("keyen")!=st.end() && s.substr(i,2)=="ce" && i+1==n-1)	{
			cout << "YES\n";
			return;
		}
		if(st.find("keye")!=st.end() && s.substr(i,3)=="nce" && i+2==n-1)	{
			cout << "YES\n";
			return;
		}
		if(st.find("key")!=st.end() && s.substr(i,4)=="ence" && i+3==n-1)	{
			cout << "YES\n";
			return;
		}
		if(st.find("ke")!=st.end() && s.substr(i,5)=="yence" && i+4==n-1)	{
			cout << "YES\n";
			return;
		}
		if(st.find("k")!=st.end() && s.substr(i,6)=="eyence" && i+5==n-1)	{
			cout << "YES\n";
			return;
		}
		if(s.substr(i,7)=="keyence" && (i==0 || i+6==n-1))	{
			cout << "YES\n";
			return;
		}
		if(s.substr(i,6)=="keyenc" && i==0)	st.insert("keyenc");
		else if(s.substr(i,5)=="keyen" && i==0)	st.insert("keyen");
		else if(s.substr(i,4)=="keye" && i==0)	st.insert("keye");
		else if(s.substr(i,3)=="key" && i==0)	st.insert("key");
		else if(s.substr(i,2)=="ke" && i==0)	st.insert("ke");
		else if(s.substr(i,1)=="k" && i==0)	st.insert("k");
	}
	cout << "NO\n";
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}