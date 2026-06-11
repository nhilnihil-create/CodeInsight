//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
int calc(int x,int lg){
	return lg+lg+__builtin_popcount(x-(1<<lg));
}
int l;
int main(){
	cin>>l;int lg;
	for(int i=0;i<=20;i++){
		if((1<<i)<=l)lg=i;
	}
	cout<<lg+1<<" "<<calc(l,lg)<<endl;
	int n=lg+1;
	for(int i=1;i<n;i++)cout<<i<<" "<<i+1<<" "<<(1<<i-1)<<endl;
	for(int i=1;i<n;i++)cout<<i<<" "<<i+1<<" "<<0<<endl;
	int L=1<<lg,R=l;
	for(int i=n-1;i>=1;i--){
		int cnt=1<<i-1;
		if(R-L>=cnt){
			cout<<i<<" "<<n<<" "<<L<<endl;
			L+=cnt;
		}
	}
	return 0;
}