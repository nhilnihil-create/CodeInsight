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

ull Euclid(ull A, ull B){
    if(A<B) swap(A, B);
    ull C = B;
    while(C != 0){
        C = A%B;
        A = B;
        B = C;
    }
    return A;
}

int main(){
	ll T;
	cin >> T;
	ll A, B, C, D;
	REP(t, T){
		cin >> A >> B >> C >> D;
		bool flag;
		if(A<B){
			flag = false;
		}else{
			if(B>D){
				flag =false;
			}else{
				if(B<=C+1){
					flag = true;
				}else{
					ll E = Euclid(B, D);
					flag = (B+A%E-E<=C);
				}
			}
		}
		cout << (flag?"Yes":"No") << endl;
	}
    return 0;
}