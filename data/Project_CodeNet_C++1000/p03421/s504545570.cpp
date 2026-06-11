#include <iostream>
using namespace std;

int main() {
	long N, A, B; cin >> N >> A >> B;
	if(A+B-1>N || A*B<N){
		cout << -1 << endl;
		return 0;
	}
	if(B==1){
		cout << 1;
		for(int i=2; i<=N; ++i) cout << ' ' << i;
		return 0;
	}
	long mx=N-A, other=(N-A)/(B-1), res=(N-A)%(B-1);
	cout << mx+1;
	for(long i=mx+2; i<=N; ++i) cout << ' ' << i;
	for(long i=1; i<B; ++i){
		if(i<=res) ++other;
		mx -= other;
		for(long c=1; c<=other; ++c) cout << ' ' << mx+c;
		if(i<=res) --other;
	}
	cout << endl;
	return 0;
}