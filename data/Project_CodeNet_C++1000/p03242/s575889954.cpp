/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200005
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


int main()
{
	string s;
	cin >> s;
	string ans;
	for (int i=0 ; i<(int)s.length() ; i++)
	{
		if(s[i] == '1')
			ans+='9';
		else
			ans+='1';
	}
	cout << ans << endl;
	return 0;
}