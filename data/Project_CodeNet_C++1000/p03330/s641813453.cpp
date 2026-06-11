#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 600, MAX_C = 32;
int N, C;
int D[MAX_C][MAX_C], col[MAX_N][MAX_N];

void solve()
{
	vector<int> same[3];
	for(int i=0;i<3;++i) same[i].resize(C+1);
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
	    for(int c=1;c<=C;++c){
		    same[(i+j)%3][c]+=D[col[i][j]][c];
	    }
	}
	ll ans = 1e16;
    for(int c1=1;c1<=C;++c1)for(int c2=1;c2<=C;++c2)if(c1!=c2)for(int c3=1;c3<=C;++c3)if(c3!=c1&&c3!=c2){
        ll cur = same[0][c1]+same[1][c2]+same[2][c3];
        ans=min(ans,cur);
    }
	cout << ans << '\n';
}

int main()
{
	cin >> N >> C;
	for(int i=1;i<=C;++i)for(int j=1;j<=C;++j) cin >> D[i][j];
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j) cin >> col[i][j];
	solve();
	return 0;
}
