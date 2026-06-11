#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 1005
const lli inf = 1e16;

struct box{
	int w,s;
	lli v;
};

lli dp[maxn][10006][2];
vector<box> order;
int n;

bool cmp(box a, box b){
	return (a.w + a.s) > (b.w + b.s);
}

lli solve(int pos, int str, int f){
	if(str < 0) return -inf;
	if(pos == n){
		return 0ll;
	}

	lli &ans = dp[pos][str][f];
	if(ans != -1) return ans;
	ans = 0;
	
	ans = max(ans, solve(pos+1,str,f));
	int val = min(str-order[pos].w, order[pos].s);
	if(!f) val = order[pos].s;
	ans = max(ans, solve(pos+1,val,1) + order[pos].v);
	return ans;
}

int main(){__
	cin >> n;
	order.resize(n);
	for(int i=0; i <n; i++){
		cin >> order[i].w >> order[i].s >> order[i].v;
	}
	sort(order.begin(),order.end(),cmp);
	memset(dp,-1,sizeof(dp));
	cout << solve(0,1e4+5,0) << endl;
	return 0;
}
