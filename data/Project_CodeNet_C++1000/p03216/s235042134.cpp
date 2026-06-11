#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n,q,k;
string s;

int main(){
	cin>>n>>s>>q;
	for(int i=0;i<q;i++){
		cin>>k;
		ll res=0,d=0,m=0,tmp=0;
		for(int j=0;j<n;j++){
			if(j>=k){
				if(s[j-k]=='D') d--,tmp-=m;
				if(s[j-k]=='M') m--;
			}
			if(s[j]=='D') d++;
			if(s[j]=='M') tmp+=d,m++;
			if(s[j]=='C') res+=tmp;
		}
		cout<<res<<endl;
	}
}