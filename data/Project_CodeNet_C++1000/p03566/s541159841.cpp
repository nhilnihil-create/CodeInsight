#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 20005;
const int N = 100;

int max_v[MAX],cur_v[MAX],t[N],v[N];

int main() {
	cout << fixed << setprecision(15);
	int n;cin>>n;
	rep(i,n) cin>>t[i];
	rep(i,n) cin>>v[i];
	int idx=0;
	rep(i,n) rep(j,t[i]) {max_v[idx++]=v[i];}
	max_v[idx]=0;
	cur_v[0]=0;
	rep1(i,idx) {
		int tmp_v=cur_v[i-1],tmp_i=i,dif_v=1000;
		while(tmp_v>=0&&tmp_i<=idx) {
			dif_v=min(dif_v,max_v[tmp_i]-tmp_v);
			dif_v=min(dif_v,max_v[tmp_i-1]-tmp_v);
			tmp_i++;tmp_v--;
		}
		if(dif_v<=0) cur_v[i]=cur_v[i-1]+dif_v;
		else cur_v[i]=cur_v[i-1]+1;
	}
	double ans=0;
	rep1(i,idx) {
		ans+=((double)cur_v[i-1]+(double)cur_v[i])/2.0;
		if(cur_v[i-1]==cur_v[i]&&cur_v[i-1]<max_v[i-1]) ans+=0.25;
	}
	cout<<ans<<endl;
}
