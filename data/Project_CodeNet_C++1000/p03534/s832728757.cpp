#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	string S;
	cin >> S;
	ll A=0, B=0, C=0;
	REP(i, S.size()){
		if(S[i]=='a') A++;
		if(S[i]=='b') B++;
		if(S[i]=='c') C++;
	}
	ll tmp = (S.size()-1)/3+1;
	if(A<=tmp&&B<=tmp&&C<=tmp){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
    return 0;
}