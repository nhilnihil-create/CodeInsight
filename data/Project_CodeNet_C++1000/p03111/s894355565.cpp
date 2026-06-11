#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 10;
int N, A, B, C;
int L[MAX_N];
int tmp[MAX_N];
int n;

ll cal(int* st, int s, int t, int goal)
{
	ll ans = 10*(t-s);
	ll len = 0;
	for(int i=s;i<=t;++i)len+=st[i];
	ans += abs(len-goal);
	return ans;
}

void solve()
{
	ll ans = 1e18;
	for(int i=1;i<(1<<N);++i)if(__builtin_popcount(i) >= 3){
	    n = 0;
	    for(int j=0;j<N;++j)if(i>>j&1)tmp[n++]=L[j];
    	sort(tmp,tmp+n);
    	do{
    		for(int i=0;i<n;++i)for(int j=i+1;j+1<n;++j){
    			ans = min(ans, cal(tmp,0,i,A)+cal(tmp,i+1,j,B)+cal(tmp,j+1,n-1,C));
    		}
    	}while(next_permutation(tmp,tmp+n));
	}
	cout << ans << '\n';
}

int main()
{
	cin >> N >> A >> B >> C;
	for(int i=0;i<N;++i) cin >> L[i];
	solve();
	return 0;
}