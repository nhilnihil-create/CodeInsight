#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 500;
int N;
int C[MAX_N],S[MAX_N],F[MAX_N];

ll go(int at, ll time)
{
	if(at == N-1) return time;
	ll x = 0;
	while(S[at]+F[at]*x < time) x++;
	return go(at+1, S[at]+F[at]*x + C[at]);
}

void solve()
{
	for(int i=0;i<N-1;++i){
		cout<< go(i, 0) << '\n';
	}	
	cout<<0<<'\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N-1;++i){
		cin >> C[i] >> S[i] >> F[i];
	}
	solve();
	return 0;
}