#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	const int MC = 30000;
	int N; cin >> N;
	cout << "2 3";
	if(N == 3) return cout << " 25" << endl, 0;
	cout << " 4 9";
	N -= 4;
	int x = 8;
	for( ; N > 1 && x <= MC ; x += 6){
		cout << ' ' << x << ' ' << x+2;
		N -= 2;
	}
	x = 15;
	for( ; N > 1 && x <= MC ; x += 12){
		cout << ' ' << x << ' ' << x+6;
		N -= 2;
	}
	while(N){
		cout << ' ' << 6*N;
		--N;
	}
	cout << endl;
	return 0;
}
