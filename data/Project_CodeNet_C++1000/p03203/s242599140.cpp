#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
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
int h,w,n;
int x[200005],y[200005];
vector<int>zip[200005];
int main(){
	scanf("%d%d%d",&h,&w,&n);

	for(int i=0;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		zip[x].pb(y);
	}
	for(int i=1;i<=h;i++) SORT(zip[i]);
	int R = 1;
	for(int i=1;i<h;i++){
		if(zip[i+1].size() && zip[i+1][0] <= R){
			cout<<i<<endl;
			return 0;
		}
		R++;
		if(zip[i+1].size() && zip[i+1][0] == R){
			R--;
		}
	}
	cout<<h<<endl;
}