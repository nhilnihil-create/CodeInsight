#include<bits/stdc++.h>

using namespace std;


typedef long long ll ;
const ll mk = 100055;
const ll logn  = 29;
const ll mod = 1e9 + 7;

#define endl "\n"
#define IOS  ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define pii pair<ll,ll>
#define pq priority_queue
#define UwU              uwu
#define UwU              Mikuwu
#define Miku             best_waifu
#define Miku_dancing     god_waving
#define Miku_singing     god_shaking
#define a_Miku           cho_doi_bot_ngu

int	main()
{
	int	N;
	cin >> N;
	int	A[2000];
	int	sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		sum += A[i];
	}
	bitset<4000000>	dp(1);
	for (int i = 0; i < N; ++i)
		dp |= (dp << A[i]);
	for (int i = (sum + 1) / 2; i <= sum; ++i) {
		if (dp.test(i)) {
			cout << i << endl;
			break;
		}
	}
}
