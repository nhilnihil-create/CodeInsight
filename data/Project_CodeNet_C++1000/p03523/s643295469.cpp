#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;

vector<ll> pw2(51,1);
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll mid(ll x,ll y,ll z){return x>y?y>=z?y:min(z,x):x>=z?x:min(y,z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll myceil(ll x,ll y){if(x<=y) return 1;else if(x%y==0) return x/y;else return x/y+1;}

//a,b x
int main(){
	rep1(i,50) pw2[i]=2*pw2[i-1];
	string sin; cin>>sin;
	string s="AKIHABARA";
	vector<string> S(16,"");
	rep(i,16){
		ll tmp=i;
		vector<ll> f(9,2);
		f[0]=tmp/pw2[3];
		tmp%=pw2[3];
		f[4]=tmp/pw2[2];
		tmp%=pw2[2];
		f[6]=tmp/pw2[1];
		tmp%=pw2[1];
		f[8]=tmp/pw2[0];
		rep(j,9){
			if(f[j]==0) continue;
			else S[i]+=s[j];
		}
	}
	//rep(i,16) cout<<S[i]<<endl;
	rep(i,16){
		if(sin==S[i]){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}