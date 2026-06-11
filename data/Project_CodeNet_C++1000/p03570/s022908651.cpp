#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int a = 0;a < i;a++){for(int b = 0;b < j;b++)cerr << v[a][b] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

int mp[1<<26];
int memo[200001];

int main()
{
	string str;
	cin >> str;
	
	
	REP(i,1<<26)
	{
		mp[i] = 100000000;
	}
	REP(i,str.size()+1)
	{
		memo[i] = 1000000;
	}
	
	int d = 0;
	memo[0] = mp[0] = 0;
	REP(i,str.size())
	{
		memo[i+1] = min(memo[i+1],memo[i]+1);
		
		d ^= (1 << (str[i] - 'a'));
		
		REP(j,26)
		{
			memo[i+1] = min(memo[i+1] ,mp[d ^ (1 << j)]+1);
		}

		memo[i+1] = min(memo[i+1] , mp[d]+1);
		mp[d] = min(memo[i+1],mp[d]);

	}
		
	cout << memo[str.size()] << endl;
	
	return 0;
}



