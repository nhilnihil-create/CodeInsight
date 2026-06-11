#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define all(v) v.begin(),v.end()
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[222222];
struct edge{int to,cost;};
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
bool prime(int a){
	if(a==1)return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)return false;
	}
	return true;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){//線分の交差判定
	double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
	double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
	double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
	double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
	return tc*td<0&&ta*tb<0;
}
void init_fact(int n){
	kaijo[0]=1;
	for(int i=1;i<=n;i++){
		kaijo[i]=kaijo[i-1]*i;
		kaijo[i]%=MOD;
	}
}
int modpow(int a,int b){
	if(b==0)return 1;
	if(b%2)return modpow(a,b-1)*a%MOD;
	int memo=modpow(a,b/2);
	return memo*memo%MOD;
}
int comb(int a,int b){
	return kaijo[a]*modpow(kaijo[a-b],MOD-2)%MOD*modpow(kaijo[b],MOD-2)%MOD;
}
int g(int x){
	x=modpow(x,MOD-2);
	return x;
}
int n,a[55],mi=INF,ma=-INF,p,m,mii,mai;
signed main(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
		if(mi>a[i]){
			mi=a[i];
			mii=i+1;
		}
		if(ma<a[i]){
			ma=a[i];
			mai=i+1;
		}
		if(a[i]>0)p++;
		if(a[i]<0)m++;
	}
	if(p&&m){
		cout<<2*n-1<<endl;
		if(abs(mi)<=abs(ma)){
			rep(i,n){
				a[i]+=ma;
				cout<<mai<<" "<<i+1<<endl;
			}
			for(int i=1;i<n;i++){
				cout<<i<<" "<<i+1<<endl;
				a[i]+=a[i-1];
			}
		}
		else{
			rep(i,n){
				a[i]+=mi;
				cout<<mii<<" "<<i+1<<endl;
			}
			for(int i=n-2;i>=0;i--){
				cout<<i+2<<" "<<i+1<<endl;
				a[i]+=a[i+1];
			}
		}
	}
	else{
		cout<<n-1<<endl;
		if(a[0]>0){
			for(int i=1;i<n;i++){
				a[i]+=a[i-1];
				cout<<i<<" "<<i+1<<endl;
			}
		}
		else{
			for(int i=n-2;i>=0;i--){
				a[i]+=a[i+1];
				cout<<i+2<<" "<<i+1<<endl;
			}
		}
	}
	return 0;
}
