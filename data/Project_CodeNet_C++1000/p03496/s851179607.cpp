#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)

int main(){
	int N; cin>>N;
	int minA = INT_MAX, maxA = INT_MIN;
	int minIx, maxIx;
	rp(i, 1, N+1){
		int a; cin>>a;
		if(maxA < a){ maxA = a; maxIx = i; }
		if(minA > a){ minA = a; minIx = i; }
	}

	if(minA == maxA) puts("0");//same
	else if(minA>=0 && maxA>=0){//all +
		cout<< N-1 <<endl;
		rp(i,1,N) cout<<i<<" "<<i+1<<endl;
	}
	else if(minA<=0 && maxA<=0){//all -
		cout<< N-1 <<endl;
		irp(i,N,1) cout<<i<<" "<<i-1<<endl;
	}
	else if(minA<=0 && maxA>=0){//mix -+
		cout<< 2*N-1 <<endl;
		if(abs(minA) > abs(maxA)){//|min|
			rp(i,1,N+1) cout<<minIx<<" "<<i<<endl;
			irp(i,N,1) cout<<i<<" "<<i-1<<endl;
		}
		// else if(abs(minA) > abs(maxA)){
		else{//|max|
			rp(i,1,N+1) cout<<maxIx<<" "<<i<<endl;
			rp(i,1,N) cout<<i<<" "<<i+1<<endl;
		}
	}

}
