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
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

int main() {
	int n;cin>>n;
	pii r[N],b[N];
	rep(i,n) cin>>r[i].first>>r[i].second;
	rep(i,n) cin>>b[i].first>>b[i].second;

	sort(b,b+n);
	bool f[N];
	rep(i,n) f[i]=false;
	rep(i,n){
		int y=-1,tj=-1;
		rep(j,n){
			if(f[j]) continue;
			if(r[j].first<b[i].first&&r[j].second<b[i].second){
				if(r[j].second>y){
					tj=j;
					y=r[j].second;
				}
			}
		}
		if(tj!=-1) f[tj]=true;
	}
	int ans=0;
	rep(i,n) if(f[i]) ans++;
	cout<<ans<<endl;
}
