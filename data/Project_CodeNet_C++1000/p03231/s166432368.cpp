#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int gcd(int a,int b){
	if(a<b) return gcd(b,a);
	int r;
	while(r=a%b){
		a=b;
		b=r;
	}
	return b;
}
int main(){
	ll n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	ll l=n*m/gcd(n,m);

	ll a=l/n,b=l/m;//aはlの中のsの間隔、bはtの間隔。l[i+a]==s[j+1],l[i]==s[j]
	ll lt=a*b/gcd(a,b);//a,bのlcm,aとbが同じl[i]のiを指すところ.l[lt*i]==s[aa*o]==t[bb*o]
	int cnt=l/lt;
	ll aa=lt/a,bb=lt/b;

	//cout<<a<<" "<<b<<" "<<lt<<" "<<cnt<<"\n";
	for(ll i=0;i<cnt;i++){
		if(s[i*aa]!=t[i*bb]) {
			cout<<-1<<"\n";
			return 0;
		}
	}
	cout<<l<<"\n";
}