#include <bits/stdc++.h>
#include <quadmath.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define EPSILON 0
int powint(int a, int x){
	int res = 1;
	REP(i,x){
		res = res *a; 
	}
	return res;
}
 
using namespace std;
 
int main(){
	int Q;
	cin>>Q;
	vector<int> A(Q);
	vector<int> B(Q);
	REP(i,Q){
		cin>>A[i]>>B[i];
	}
	REP(i,Q){
		long long int a=A[i];
		long long int b=B[i];
		long long int u=ceil(sqrt(a*b))-1;
		long long int ans=2*u;
		//if(sqrt(a*b)==ceil(sqrt(a*b))){
		//	ans++;
		//}
		long long int t=min(a,b);
		//if( int(ceil(double(a*b)/t)) - 1 == max(a,b) ){
		ans--;//既にあるやつのぶん
		//}
 
		if(a==b){
			ans++;
		} else 	if((long long int)((long double)(a*b)/u +EPSILON) == u){
			ans--;
		}
 
		if(ceil((long double)(a*b)/u) == ((long double)(a*b)/u) && (long long int)((long double)(a*b)/u +EPSILON) == u+1){
			ans--;
		}
 

		/*
		debug(a);
		debug(b);
		debug(u);
		*/
		cout<<ans<<endl;
	}
	return 0;
}