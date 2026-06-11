#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define pb push_back
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[200010];
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
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
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
	if(b>a)return 0;
	if(a==b)return 1;
	return kaijo[a]*modpow(kaijo[a-b],MOD-2)%MOD*modpow(kaijo[b],MOD-2)%MOD;
}
//int g(int x){
//	x=modpow(x,MOD-2);
//	return x;
//}
int n,m,cnt[100010],ans[100010];
vector<int>v[100010];
queue<int>q;
signed main(){
	cin>>n>>m;
	rep(i,n-1+m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].pb(b);
		cnt[b]++;
	}
	rep(i,n)if(!cnt[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int to:v[x]){
			cnt[to]--;
			if(!cnt[to]){
				ans[to]=x+1;
				q.push(to);
			}
		}
	}
	rep(i,n)cout<<ans[i]<<endl;
	return 0;
}
