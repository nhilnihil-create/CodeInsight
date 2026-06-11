#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define fi first
#define sec second
#define pb push_back
#define mp make_pair
#define rep(a,b,c) for(ll a=1;a<=b;a+=c)
#define repp(a,b,c,d) for(ll a=b;a<=c;a+=d)

const double PI=acos(-1);
const long double EPS=1e-12;
const ll MOD=1e9+7;
const int INF=1<<30;


using namespace std;

vector<ll>pr;
bool vis[30005];
void pre(){
	pr.pb(2);
	repp(i,3,30000,2){
		if(!vis[i]){
			pr.pb(i);
			repp(j,i*i,30000,i){
				vis[j]=true;
			}
		}
	}
}


int main(){
	ll a,b,x;
	pre();
	cin>>a>>b;
	if(a%b==0)cout<<-1<<endl;
	else{
		x=__gcd(a,b);
		a/=x;
		b/=x;
		int sz=pr.size();
		for(int i=0;i<sz;i++){
			if((a*pr[i])%b!=0){
				cout<<a*x*pr[i]<<endl;
				return 0;
			}
		}
		cout<<-1<<endl;
	}
}