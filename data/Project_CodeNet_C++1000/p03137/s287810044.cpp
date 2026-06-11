#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(),(a).rend())
#define ll long long
#define pb(a) push_back(a)

#define PRINTV(v) {for(ll deB=0; deB<(v).size(); deB++){cout << (v)[deB] << " ";}cout << endl;}

int main(){
	
	
	ll N, M;
	cin >> N >> M;
	vector<ll> X(M);
	REP(i,M) cin >> X[i];

	SORT(X);

	vector<ll> D(M-1);
	REP(i, X.size()-1){
		D[i] = X[i+1] - X[i];
	}

	sort(D.begin(), D.end(), std::greater<int>() );

	N--;
	ll ans = 0;
	REP(i, D.size()){
		if(N > 0){
			N--;
		}else{
			ans += D[i];
		}
	}
	
	cout << ans << endl;
	return 0;

abnormal:
	cout << "No" << endl;
	return 0;
}