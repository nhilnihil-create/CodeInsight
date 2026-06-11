#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	ll K, A, B; cin >> K >> A >> B;

	ll cnt = 1;

	if(A+1 >= B){
		cnt += K;
	}else{
		if(K > A){
			ll tmp = B - A;
			cnt--;
			K -= A - 1;
			ll hoge = K/A + 1;
			ll foo = K/2*tmp + K%2 + A;
			ll z = min(hoge, K%A) * B;
			cnt += max(foo, z);

		}else if(K <= A) cnt += K;
	}

	cout << cnt << endl;


	return 0;


}
