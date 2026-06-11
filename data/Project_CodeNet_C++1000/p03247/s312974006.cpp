#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
ll m_max = 40;
vector<ll> tfs;
vector<ll> tf(ll r){
	ll cur = 0;
	vector<ll> res;
	for(int i=0;i<tfs.size();i++){
		if(cur<=r){
			res.pb(1);
			cur += tfs[i];
		}
		else{
			res.pb(-1);
			cur -= tfs[i];
		}
	}
	reverse(res.begin(),res.end());
	return res;
}
int main(){
	ll n;
	cin>>n;
	vector<ll> x,y;
	for(int i=0;i<n;i++){
		ll tx,ty;
		cin>>tx>>ty;
		x.pb(tx);
		y.pb(ty);
		if( (abs(tx+ty)) % 2 != (abs(x[0]+y[0])) %2){
			cout<<-1<<endl;
			return 0;
		}
	}
	if( (abs(x[0]+y[0])) % 2 == 0){
		cout<<m_max<<endl;
		cout<<1<<" ";
		tfs.pb(1);
		ll cur = 1;
		for(int i=1;i<=m_max-1;i++){
			cout<<cur<<" ";
			tfs.pb(cur);
			cur = cur*2;
		}
		cout<<endl;
	}
	else{
		cout<<m_max<<endl;
		ll cur = 1;
		for(int i=1;i<=m_max;i++){
			cout<<cur<<" ";
			tfs.pb(cur);
			cur = cur * 2;
		}
		cout<<endl;
	}
	reverse(tfs.begin(),tfs.end());
	for(int i=0;i<n;i++){
		vector<ll> xp,yp;
		xp = tf(x[i]-y[i]);
		yp = tf(x[i]+y[i]);
		for(int j=0;j<=39;j++){
			if(xp[j]==1 && yp[j]==1){
				cout<<"R";
			}
			if(xp[j]==-1 && yp[j]==-1){
				cout<<"L";
			}
			if(xp[j]==-1 && yp[j]==1){
				cout<<"U";
			}
			if(xp[j]==1 && yp[j]==-1){
				cout<<"D";
			}
		}
		cout<<endl;
	}
	return 0;
}