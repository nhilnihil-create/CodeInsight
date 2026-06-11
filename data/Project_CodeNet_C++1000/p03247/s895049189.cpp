#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN=1e3+7;

int n;
struct node {
	int x,y;
}N[MAXN];

ll gd(ll i,ll x,ll y) {
	return abs(N[i].x-x)+abs(N[i].y-y);
}

int m=40,can;
ll d[40];
char ch[40];

void solve(int num) {
	ll X=0,Y=0;
	if(m==33) X=1;
	ch[33]='R';
	for(int i=1;i<=32;i++) {
		if(gd(num,X+d[i],Y)<=d[i]-1) {
			X=X+d[i];
			ch[i]='R';
			continue;
		}
		if(gd(num,X-d[i],Y)<=d[i]-1) {
			X=X-d[i];
			ch[i]='L';
			continue;
		}
		if(gd(num,X,Y+d[i])<=d[i]-1) {
			Y=Y+d[i];
			ch[i]='U';
			continue;
		}
		if(gd(num,X,Y-d[i])<=d[i]-1) {
			Y=Y-d[i];
			ch[i]='D';
			continue;
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<ch[i];
	}
	cout<<endl;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>N[i].x>>N[i].y;
		if(i==1) can=abs(N[i].x+N[i].y)%2;
		if(can!=abs(N[i].x+N[i].y)%2) {
			cout<<-1<<endl;
			return 0;
		}
	}
//	can=can^1;
	m=33-can;
	cout<<m<<endl;
	for(int i=1;i<=32;i++) {
		d[i]=(1ll<<(32-i));
		cout<<d[i]<<" ";
	}
	if(m==33) cout<<1<<endl;
	else cout<<endl;
	for(int i=1;i<=n;i++) {
		solve(i);
	}
}