//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL gcd(LL a,LL b){
//	cout<<a<<" "<<b<<endl;
	if(b==0) return a;
	return gcd(b,a%b);
}
void solve(){
	LL a,b,c,d;
	cin>>a>>b>>c>>d;
	//初始 每天买 小于c时加d
	if(a<b){
		puts("No");
		return;
	}
	if(b>d){
		puts("No");
		return ;
	} 
	 LL g = __gcd(b, d), t = a % g - g;
  	if(t<c-b+1){
  		puts("Yes");
  	}
  	else{
  		puts("No");
  	}
}
int main(){
	int t;
	cin>>t;
	while(t--){solve();	}
	return 0;
}
