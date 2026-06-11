#include<bits/stdc++.h>
#define lol(i,n) for(int i=0;i<n;i++)
#define fi first
#define sc second
typedef long long ll;

using namespace std;
#define N 200010
ll h,w,n;
pair<ll,ll> d[N];
int main(){
    cin>>h>>w>>n;
    lol(i,n)cin>>d[i].fi>>d[i].sc;
    sort(d,d+n);
    ll k=0;
    lol(i,n){
	ll x=d[i].fi,y=d[i].sc;
	if(y<x+k)return cout<<x-1<<endl,0;
	if(y==x+k)k--;
    }
    cout<<h<<endl;
    return 0;
}
