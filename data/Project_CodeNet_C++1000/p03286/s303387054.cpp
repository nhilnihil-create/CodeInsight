#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

void solve()
{
	if(!N) cout << 0 << '\n';
	else{
		string s;
		while(N){
			int re = N % 2;
			if(re < 0) N -= 1;
			s += re?'1':'0';
			N/=-2;
		}
		reverse(s.begin(),s.end());
		cout << s << '\n';
	}
	return;
}

int main()
{
	cin >> N;
	solve();
	return 0;
}