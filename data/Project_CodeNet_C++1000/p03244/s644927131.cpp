#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
ii cnt[2][100001];
int a[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n; cin >> n;
	for(int i=0; i<=1e5; i++){
		cnt[0][i].fi=cnt[1][i].fi=n/2;
		cnt[0][i].se=cnt[1][i].se=i;
	}
	for(int i=0; i<n; i++){
		cin >> a[i];
		cnt[i%2][a[i]].fi--;
	}
	sort(begin(cnt[0]),end(cnt[0]));
	sort(begin(cnt[1]),end(cnt[1]));
	if(cnt[0][0].se==cnt[1][0].se){
		cout << min(cnt[0][0].fi+cnt[1][1].fi,cnt[0][1].fi+cnt[1][0].fi) << endl;
	}else{
		cout << cnt[0][0].fi+cnt[1][0].fi << endl;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
