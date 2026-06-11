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
const int MAX = 100000;
const int N = 50;

long long X[N],Y[N],X2[N],Y2[N];

int main() {
	int n,k2;cin>>n>>k2;
	rep(i,n) {cin>>X[i]>>Y[i];X2[i]=X[i];Y2[i]=Y[i];}
	long long ans=INFL;
	sort(X,X+n);sort(Y,Y+n);
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			for(int k=0;k<n-1;k++) {
				for(int l=k+1;l<n;l++) {
					int c=0;
					rep(m,n) if(X2[m]>=X[i]&&X2[m]<=X[j]&&Y2[m]>=Y[k]&&Y2[m]<=Y[l]) c++;
					if(c>=k2) ans=min(ans,(X[j]-X[i])*(Y[l]-Y[k]));
				}
			}
		}
	}
	cout<<ans<<endl;
}
