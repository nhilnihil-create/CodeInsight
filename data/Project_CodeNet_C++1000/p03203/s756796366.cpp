#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()


int h,w,n,ni=1,nj=1;
int pos[200010];
ll ans=INF;
map<P,bool>mp;

void find(){
	queue<P>q;
	if(!mp[P(2,1)])q.push(P(2,1));
	while(!q.empty()){
		P p=q.front();
		q.pop();
		if(p.fr+1==h+1)continue;
		if(p.sc+1==w+1)continue;
		if(pos[p.sc+1])continue;
		if(!mp[P(p.fr,p.sc+1)]){
			pos[p.sc+1]=p.fr;
			if(!mp[P(p.fr+1,p.sc+1)])q.push(P(p.fr+1,p.sc+1));
		}
		else{
			if(!mp[P(p.fr+1,p.sc)])q.push(P(p.fr+1,p.sc));
		}
	}
	return;
}

P p[200010];

void input(){
	cin>>h>>w>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].fr>>p[i].sc;
		mp[P(p[i].fr,p[i].sc)]=true;
	}
	return;
}

void solve(){
	pos[1]=1;
	find();
	for(int i=0;i<n;i++){
		if(!pos[p[i].sc])continue;
		if(pos[p[i].sc]<p[i].fr)ans=min(ans,p[i].fr-1);
	}
	if(ans==INF)ans=h;
	cout<<ans<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}