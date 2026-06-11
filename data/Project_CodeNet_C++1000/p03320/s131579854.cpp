#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

ll S(ll x){
	ll S = 0;
	while(x>0){
		S += x%10;
		x /= 10;
	}
	return S;
}

double snuke(ll x){
	return double(x)/S(x);
}

int main(){
	ll K;
	cin >> K;
	vector<ll> cand;
	ll b = 1;
	for(int i=0;i<15;i++){
		for (int j=1;j<150;j++){
			cand.push_back(b * (j+1) - 1);
		}
		b *= 10;
	}
	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());
	for(ll i=0;i<cand.size();i++){
		for(ll j=i+1;j<cand.size();j++){
			if (snuke(cand[i]) > snuke(cand[j])){
				cand.erase(cand.begin() + i);
				i--;
				break;
			}
		}
	}

	REP(i, K){
		cout << cand[i] << endl;
	}
    return 0;
}