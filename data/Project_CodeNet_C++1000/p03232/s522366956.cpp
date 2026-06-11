/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n,a[100000+1];
LL res=0;
const int MOD=1e9+7;
LL my_pow(LL A,LL B){
	if(!B) return 1;
	LL tmp=my_pow(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1){
		tmp*=A;
		tmp%=MOD;
	}
	return tmp;
}
LL div_(LL A,LL B){
	return A*my_pow(B,MOD-2);
}
int main(){
	fastio;
	 cin>>n;
	 rb(i,1,n)
	 	cin>>a[i];
	int A,B;
	A=1;
	B=n;
	LL sum=0;
	rb(i,1,n){
		sum+=div_(1,i);
		sum%=MOD;
	}
	rb(i,1,n){
		if(i!=1){
			sum+=div_(1,++A);
			sum-=div_(1,B--);
			sum+=MOD;
			sum%=MOD;
		}
		res+=a[i]*sum,res%=MOD; 
	}
	rb(i,1,n)
	{
		res*=i,res%=MOD;
	}
	cout<<res;
	return 0;
}
