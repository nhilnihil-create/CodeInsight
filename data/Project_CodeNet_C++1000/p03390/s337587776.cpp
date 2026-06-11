#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	int n;
	cin >> n;
	ll A, B;
	for (int i=0;i<n;i++){
		cin >> A >> B;
		if (A>B) swap(A, B);
		ll C = (ll)sqrt(A*B);
		if (A*B==C*C) C--;
		if(A==B){
			cout << 2*A-2 << endl;
		}else if(A+1==B){
			cout << 2*A-2 << endl;
		}else if(C*(C+1)>=A*B){
			cout << 2*C-2 << endl;
		}else{
			cout << 2*C-1 << endl;
		}
	}
    return 0;
}