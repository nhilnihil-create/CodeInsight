#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int(i)=int (a);i<=int (b);i++)
#define ff(i,a,b) for(int (i)=int (a);i<int (b);i++)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ld long double
#define pii pair<int,int>
const int N=1e6+6;
pii a[N];
int n,m;
bool cmp(pii a,pii b){
	return a.se<b.se;
}
int main(){
	cin>>n>>m;
	ff(i,0,m){
		cin>>a[i].fi>>a[i].se;
	}
	sort(a,a+m,cmp);
	int last=0,ans=0;
	ff(i,0,m){
		if(a[i].fi>=last){
			last=a[i].se;
			ans++;
		}
	}
	cout<<ans;
}