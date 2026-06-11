#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int cx,cy,x,y;
string s;
int n;
vector<int>X,Y;
bitset<10005>B;
bool ok(vector<int>vec,int num){
	B.reset();
	B[0] = 1;
	int sum = 0;
	rep(i,vec.size()){
		B |= (B<<vec[i]);
		sum += vec[i];
	}
	rep(i,sum+1){
		if(sum-i*2 == num && B[i]) return 1;
	}
	return 0;
}
int main(){
	cin>>s>>x>>y; n = s.size();
	int cur = 0;
	bool beg = 0;
	rep(i,n){
		if(s[i] == 'F'){
		    if(beg) (cur==0?X:Y).back()++;
		    else x--;
		}
		else{
		    cur ^= 1;
		    beg = 1;
		    (cur==0?X:Y).pb(0);
		}
	}
	if(ok(X,x) && ok(Y,y)) puts("Yes"); 
	else puts("No");
}
