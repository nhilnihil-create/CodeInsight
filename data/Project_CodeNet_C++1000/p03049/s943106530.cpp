#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)

ll N;
ll x,y,z;
ll ans;
string s[10005];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

rep(i,N) cin>>s[i];

rep(i,N){
	rep1(j,s[i].size()){
		if(s[i][j-1]=='A'&&s[i][j]=='B') ans++;
	}
}

rep(i,N){
	ll n=s[i].size();
	if(s[i][0]=='B'&&s[i][n-1]!='A') x++;
	if(s[i][0]=='B'&&s[i][n-1]=='A') z++;
	if(s[i][0]!='B'&&s[i][n-1]=='A') y++;
}

if(x>=y){
	ans+=y+z;
	if(y==0&&x==0&&z>0) ans--;
}else{
	ans+=x+z;
}

cout<<ans<<endl;

}
	
