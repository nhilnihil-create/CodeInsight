// D - Non-decreasing
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)

int main(){
	int N; cin>>N;
	int ix = 1, sign = 0;//-+ : min|max
	rp(i, 1, N+1){
		int a; cin>>a;
		if(abs(sign) < abs(a)){ sign = a; ix = i; }
	}

	cout<< 2*N-1 <<endl;
	rp(i, 1, N+1) printf("%d %d\n", ix,i);

	if(sign < 0) irp(i, N, 1) printf("%d %d\n", i,i-1);
	else rp(i, 1, N) printf("%d %d\n", i,i+1);
}