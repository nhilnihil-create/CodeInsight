// oh, the less I know the better
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz
#include <bits/stdc++.h>
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define sz(x) int(x.size())
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = (1 << 20);

int bit;
int a[N];
ii trash = {-1,-1};
pair<ii,ii> dp[N]; // {value, index}

void show(pair<ii,ii> x){
	printf("First value = (%d,%d)\n",x.fst.fst,x.fst.snd);
	printf("Second value = (%d,%d)\n",x.snd.fst,x.snd.snd);
}

void relax(pair<ii,ii> &ans, pair<ii,ii> par){
	vector<ii> vec = {ans.fst,ans.snd,par.fst,par.snd};
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int l = sz(vec);
	ans = make_pair( vec[l-1], vec[l-2] );
}

pair<ii,ii> go(int msk){
	pair<ii,ii> &ans = dp[msk];
	if(ans.fst != trash) return ans;
	ans = make_pair( make_pair(a[msk],msk),trash);
	for(int i = 0; i < bit; ++i){
		if(msk & (1 << i)){
			// turn off
			auto par = go( msk & (~(1 << i)) );
			relax(ans,par);
		}
	}
	//printf("Msk = %d\n",msk);
	//show(ans);
	return ans;
}

int main(){

	fastio;
	int n;
	cin >> n;
	bit = n;
	n = (1 << n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	REP(i,N) dp[i] = make_pair(trash,trash);
	dp[0] = make_pair(make_pair(a[0],0),trash);
	go(n-1);
	vector<int> ans(n);
	for(int i = 1; i < n; ++i){
		ans[i] = dp[i].fst.fst + dp[i].snd.fst;
		ans[i] = max(ans[i],ans[i-1]);
		cout << ans[i] << endl;
	}

	return 0;
}
