#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
constexpr int R=5e6+69, INF=2e9+6969;

int qq;

int main()
{
	string s;
	cin >> s;
	vector <int> v(4);
	for(int i=0;i<4;++i)
	{
		v[i]=s[i]-'0';
	} 
	for(int i=0;i<8;++i)
	{
		int sum = v[0];
		for(int j=0;j<3;++j)
		{
			int cur = v[j+1];
			if(i&(1<<j)) cur*=-1;
			sum+=cur;
		}
		if(sum==7)
		{
			printf("%d", v[0]);
			for(int j=0;j<3;++j)
			{
				printf("%c", ((i&(1<<j)) ? '-' : '+'));
				printf("%d", v[j+1]);
			}
			printf("=7\n");
			break;
		}
	}
	return 0;
}
