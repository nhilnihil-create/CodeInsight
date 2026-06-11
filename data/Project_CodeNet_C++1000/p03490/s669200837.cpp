#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
bitset<35000> x,y;
int main(){
	ll xx,yy;
	string s;
	cin>>s>>xx>>yy;
	ll n=s.size();
	ll spos = 0;
	while(spos<n && s[spos] == 'F'){
		xx--;
		spos++;
	}
	vector<ll> xmv,ymv;
	ll mde = 0,cnt = 0;
	for(int i=spos;i<n;i++){
		if(s[i]=='T'){
			if(mde == 0){
				xmv.pb(cnt);
			}
			else{
				ymv.pb(cnt);
			}
			cnt = 0;
			mde=1-mde;
		}
		else{
			cnt++;
		}
	}
	if(mde == 0){
		xmv.pb(cnt);
	}
	else{
		ymv.pb(cnt);
	}
	/*for(int i=0;i<xmv.size();i++){
		cout<<xmv[i]<<endl;
	}
	for(int i=0;i<ymv.size();i++){
		cout<<ymv[i]<<endl;
	}*/
	ll ze = 17000;
	x.set(ze);
	for(int i=0;i<xmv.size();i++){
		x = (x<<xmv[i])|(x>>xmv[i]);
	}
	y.set(ze);
	for(int i=0;i<ymv.size();i++){
		y = (y<<ymv[i])|(y>>ymv[i]);
	}
	if( x[xx+ze] & y[yy+ze] ){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}