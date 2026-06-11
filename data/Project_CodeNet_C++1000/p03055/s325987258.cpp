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
typedef tuple<ll,ll,ll> Tu;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const double PI=3.14151926535;
const ll INFl=(ll)9223372036854775807/2;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
const ll tMOD=(ll)998244353;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
//int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int n;
vector<int> v[200100];
int dia=0;
void calc(){
	int t[200100];
	fill(t,t+200100,-1);
	queue<int> q;
	q.push(0);
	t[0]=0;
	int ne=0;
	while(q.size()){
		int u=q.front();q.pop();
		ne=u;
		for(int i=0;i<v[u].size();i++){
			if(t[v[u][i]]!=-1)continue;
			t[v[u][i]]=t[u]+1;
			q.push(v[u][i]);
		}
	}
	fill(t,t+200100,-1);
	q.push(ne);
	t[ne]=0;
	//cout<<ne<<endl;
	ne=0;
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=0;i<v[u].size();i++){
			if(t[v[u][i]]!=-1)continue;
			t[v[u][i]]=t[u]+1;
			ne=max(ne,t[v[u][i]]);
			q.push(v[u][i]);
		}
	}
	dia=ne;
}
int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	calc();
	//cout<<dia<<endl;
	if(dia%3==1){
		cout<<"Second"<<endl;
	}else{
		cout<<"First"<<endl;
	}
	return 0;
}