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
const int N = 100;

vector<pii> G[MAX];
int d[MAX];

int main() {
	long long k;cin>>k;
	rep(i,k) {
		G[i].push_back(pii(1,(i+1)%k));
		G[i].push_back(pii(0,i*10%k));
		d[i]=INF;
	}
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push(pii(0,1));
	d[1]=0;
	while(!Q.empty()){
		pii p=Q.top();Q.pop();
		for(auto i:G[p.second]) {
			if(d[i.second]>d[p.second]+i.first) {
				d[i.second]=d[p.second]+i.first;
				Q.push(i);
			}
		}
	}
	cout<<d[0]+1<<endl;
}
