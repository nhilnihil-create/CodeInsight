#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define INF 1000000000000000
#define fi first
#define se second
#define all(v) v.begin(),v.end()
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct edge{int to,cost;};
typedef pair<int,int> P;
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
int kaijo(int n){
	int ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	return ans;
}
int modpow(int a,int b){
	if(b==0)return 1;
	if(b%2)return modpow(a,b-1)*a%MOD;
	return modpow(a,b/2)*modpow(a,b/2)%MOD;
}
int comb(int a,int b){
	return kaijo(a)*modpow(kaijo(a-b),MOD-2)%MOD*modpow(kaijo(b),MOD-2)%MOD;
}
int n,a[364364],b[364364],mi=1145141919,sum;
signed main(){
	cin>>n;
	rep(i,n){
		cin>>a[i]>>b[i];
		if(a[i]>b[i])mi=min(mi,b[i]);
		sum+=a[i];
	}
	if(mi==1145141919)cout<<0<<endl;
	else cout<<sum-mi<<endl;
	return 0;
}
