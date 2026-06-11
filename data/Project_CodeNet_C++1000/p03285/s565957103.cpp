// B - Cakes and Donuts
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int N; cin>>N;
	bool ok = false;
	rep(x, N/4+1) rep(y, N/7+1)
		if(N == 4*x + 7*y) ok = true;
	puts(ok? "Yes": "No");
}
