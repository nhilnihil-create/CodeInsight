#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
//#define repitr(itr, st) for(auto itr = st.begin(); itr != st.end(); ++itr)
#define P_B push_back
#define PO_B pop_back
#define E_B emplace_back
#define M_P make_pair
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl
#define print(x) printf("%lld ", x)

using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<vector<int> >;
using VVL = vector<vector<ll> >;
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//const ll LINF = (ll)1e18 - 1;
//const int INF = 1e9 - 1;
//int:±2*10^9くらい　ll:±9*10^18くらい



void Main(){
	int M, K, m;
	cin >> M >> K;
	//m = pow(2, M);
	m = (1 << M);
	if(K >= m){
		cout << -1 << endl;
		return;
	}else if(M == 1){
		if(K == 1){
			cout << -1 << endl;
			return;
		}else if(K == 0){
			cout << "0 0 1 1" << endl;
			return;
		}
	}

	rep(i, m){
		if(i == K) continue;
		print(i);
	}
	print(K);
	rep(i, m){
		ll x = m-1-i;
		if(x == K) continue;
		print(x);
	}
	cout << K << endl;

}

int main()
{
	Main();

  return 0;
}
