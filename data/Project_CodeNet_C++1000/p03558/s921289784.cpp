#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define repU(i,s,t) for(int i = (s); i <= (t); ++i)
#define repD(i,t,s) for(int i = (t); i >= (s); --i)
#define all(v)  begin(v),end(v)
#define clr(v) fill(all(v),0)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n - 1)/(d) + 1)
#define parity(a,b) (((a)^(b)) & 1 ^ 1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = -1 + (1 << 30);
const ll INF_64 = -1 + (1LL << 62);
const int MOD = 1e9 + 7;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int k; cin>>k;
	deque<int> deq;
	int dist[100000];
	fill(all(dist),INF_32);
	deq.puf(1),dist[1] = 1;
	while(!deq.empty()){
		int t = deq.front();
		deq.pof();
		if(dist[t * 10 % k] > dist[t]) dist[t * 10 % k] = dist[t],deq.puf(t * 10 % k);
		if(dist[(t + 1) % k] > 1 + dist[t]) dist[(t + 1) % k] = dist[t] + 1,deq.pub((t + 1) % k);
	}
	cout<<dist[0]<<endl;
}
