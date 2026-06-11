#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100001

string s;
int N;
int num = 0;

int fw[maxn];

void upd(int p,int v){ //update position p by +=v
	for (int i=p; i<=N; i+= (i&(-i))){
		fw[i] += v;
	}
}


void update_range(int a,int b, int c){ //update position a to b by +=c
	upd(a,c); //upd function from the PURQ fenwick
upd(b+1,-c);
}

int qry(int p){ //query p
	int ans = 0;
	for (int i = p; i>0; i -= (i&(-i))){
		ans += fw[i];
	}
	return ans;
}

bool A[maxn];
	
vpi edges;

int main(){
	fast;
	
	cin>>s;
	N = s.size();
	
	
	FOR(i,0,N-1){
		if (s[i] == '1'){
			A[i+1] = 1;
			num++;
		}else A[i+1] = 0;
	}
	
	if (!A[1]){
		cout<<-1;
		return 0;
	}

	FOR(i,1,N){
		if (A[i] != A[N-i]){
			cout<<-1;
			return 0;
		}
	}
	
	if (A[N]){
		cout<<-1;
		return 0;
	}
	
	if (N%2 == 0 && A[N/2]) num++;
	
	FOR(i,1,num){
		if (i > 1) edges.pb(pi(i-1,i));
		update_range(1,i,1);
	}
	
	int cur = num+1;

	DEC(i,num,1){
		while (!A[qry(i)] && cur <= N){
			edges.pb(pi(i,cur));
			update_range(1,i,1);
			
			cur++;
		}
	}
	
	
	while (cur < N+1){
		edges.pb(pi(1,cur));
		cur++;
	}
	

	aFOR(i,edges) cout<<i.f<<' '<<i.s<<'\n';
			
	
	
	
	
	
}

