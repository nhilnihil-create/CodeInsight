#include <bits/stdc++.h>

using namespace std;

#define FOR(i, s, e)   for(int i = (s); i < (e); i++)
#define FOR64(i, s, e) for(ll  i = (s); i < (e); i++)
#define ALL(x)         (x).begin(), (x).end()
#define SORT(b, e)     sort((b), (e))
#define REV(b, e)      reverse((b), (e))
#define VSORT(v)       sort((v).begin(), (v).end())
#define VREV(v)        reverse((v).begin(), (v).end())
#define pb(a)          push_back(a)
#define INF            999999999

typedef long long ll;

int main()
{
	ll N, P;
	cin >> N >> P;

	if(N == 1){
		cout << P << endl;
		return 0;
	}

	ll res = 1;
	ll cur = P;
	for(ll k = 2; k * k <= P; k++){
		int cnt = 0;
		while(cur % k == 0){
			cur /= k;
			cnt++;
		}

		res *= pow(k, cnt / N);
	}

	cout << res << endl;

	return 0;
}

