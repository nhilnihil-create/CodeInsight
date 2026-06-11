#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

bool ok=true;
ll n,l=1;
string s;

void init(){
	cin>>s;
	n = s.size();
	s="0"+s;
}

int main(void){
	init();
	reg(i,0,n)if(s[i]!=s[n-i])ok=false;
	if(s[1]=='0')ok=false;
	if(!ok){
		cout<<-1<<endl;
		return 0;
	}
	reg(i,1,n-1){
		cout<<l<<" "<<i+1<<endl;
		if(s[i]=='1'){
			l=i+1;
		}
	}
	return 0;
}