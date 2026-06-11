#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int n = s.size();
	int a = 0, b = 0, c = 0;
	rep(i, n){
		if(s[i] == 'a')
		{ 
			a++;
		}else if(s[i] == 'b'){
			b++;
		}else{
			c++;
		}
	}

	if(abs(a-b) >= 2 || abs(b-c) >= 2 || abs(c-a) >= 2){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
}