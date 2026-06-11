#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(ll i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n,m;
ll in_edge[100100]={};
vector<ll> node[100100];
int main(){
	cin>>n>>m;
	REP(i,n-1+m){
		ll a,b;
		cin>>a>>b;
		a--,b--;
		in_edge[b]++;
		node[a].push_back(b);
	}
	int root;
	REP(i,n){
		if(in_edge[i]==0)root=i;
	}
	queue<ll> q;
	q.push(root);
	ll ans[n];
	ans[root]=0;
	while(q.size()){
		ll q1=q.front();q.pop();
		for(int i=0;i<node[q1].size();i++){
			in_edge[node[q1][i]]--;
			if(in_edge[node[q1][i]]==0){
				ans[node[q1][i]]=q1+1;
				q.push(node[q1][i]);
			}
		}
	}
	REP(i,n){
		cout<<ans[i]<<endl;
	}
	return 0;
}