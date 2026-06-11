// D - Non-decreasing
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)

int main(){
	int N; cin>>N;
	int ix = 1, minmaxA = 0;
	rp(i, 1, N+1){
		int a; cin>>a;
		if(abs(minmaxA) < abs(a)){ minmaxA = a; ix = i; }
	}
	cout<< 2*N-1 <<endl;
	rp(i, 1, N+1) cout<< ix <<" "<< i <<endl;
	if(minmaxA<0) irp(i, N, 1) cout<< i <<" "<< i-1 <<endl;
	else rp(i, 1, N) cout<< i <<" "<< i+1 <<endl;
}