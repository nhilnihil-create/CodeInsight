#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n,k,ch[100010],cnt;
vector<ll>a[100010];
void dep(ll now){
	if(now!=cnt&&a[now].size()==1){
		return;
	}
	for(ll i=0;i<a[now].size();i++){
		ll next=a[now][i];
		if(ch[next]!=-1){
			continue;
		}
		ch[next]=0;
		dep(next);
	}
}
int main() {
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		ch[i]=-1;
	}
	for(ll i=0;i<k;i++){
		ll x,y,c;
		cin>>x>>y>>c;
		x--;y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(ll i=0;i<n;i++){
		if(ch[i]==0){
			continue;
		}
		ch[i]=1;
		cnt=i;
		dep(i);
	}
	cnt=0;
	for(ll i=0;i<n;i++){
		cnt+=ch[i];
	}
	cout << cnt;
	// your code goes here
	return 0;
}