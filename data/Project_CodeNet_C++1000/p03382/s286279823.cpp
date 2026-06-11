#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	sort(begin(a),end(a));
	ll maxv=a.back();
	//nCk=n*(n-1)*....*(n-k+1)/k!のため、nは大きいほど良いことがわかる
	auto k=lower_bound(a.begin(),a.end(),(maxv+1)/2);
	ll ansk;
	if(*k==(maxv+1)/2)ansk=*k;
	else if(*(k)-(maxv+1)/2<(maxv+1)/2-*prev(k))ansk=*(k);
	else ansk=*prev(k);
	//真ん中((maxv+1)/2)からなるべく近いもの選ぶ
	cout<<maxv<<" "<<ansk<<endl;
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
