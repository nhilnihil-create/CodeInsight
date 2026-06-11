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
map<LL,int> M;
int main(){
	fastio;
	LL n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	swap(s,t);
	LL res=n*m/__gcd(n,m);
	LL now=1;
	rb(i,1,m){
		
//		cout<<now<<endl;
		M[now]=(int)(s[i-1]-'a'+1);now+=res/m;
	}
	now=1;
	rb(i,1,n){
		
		if(M[now]){
//			cout<<now<<endl;
			if(M[now]!=(int)(t[i-1]-'a'+1)){
				cout<<-1<<endl;
				return 0;
			}
		}now+=res/n;
	}
	cout<<res<<endl;
	return 0;
}
