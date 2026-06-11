#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

LL gcd(LL x, LL y){
	return y==0?x:gcd(y,x%y);
}

bool solve(LL A, LL B, LL C, LL D){
	if(A < B || D < B) return 0;
	if(B+1 <= C) return 1;
	if(A%B > C) return 0;
	LL g = gcd(B,D);
	LL e = A%g;
	LL f = (C-e)/g;
	LL p = (D/g)%(B/g);
	if(B/g <= f+1) return 1;
	return p == 0;
}

int main(){
	int T; cin >> T;
	repp(rep_T,0,T){
		LL A,B,C,D; cin >> A >> B >> C >> D;
		cout << (solve(A,B,C,D)?"Yes":"No") << endl;
	}
	return 0;
}
