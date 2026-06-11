#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i, n) for(ll i=(ll)(n-1);i>=0;i--)
#define FOR(i, a, b) for(ll i=(ll)(a); i<=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a);i>=(ll)(b); i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

signed main()
{
	int N;
	cin >> N;
	vector<int> C(N);
	vector<int> S(N);
	vector<int> F(N);
	REP(i, N-1){
		cin >> C[i] >> S[i] >> F[i];
	}
	REP(i, N-1){
		ll time = 0;
		for(int k=i; k<N-1; k++){
			if(time<=S[k]){
				time = S[k]+C[k];
			}else if(time%F[k]==0){
				time += C[k];
			}else{
				time = ((int)(time/F[k])+1)*F[k]+C[k];
			}
		}
		cout << time << endl;
	}
	cout << 0 << endl;
}
