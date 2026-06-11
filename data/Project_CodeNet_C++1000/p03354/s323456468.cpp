#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
struct dsu{
	std::vector<int> par,rank;
	dsu(int n):par(n+1),rank(n+1,1){
		rep(i,1,n+1) par[i]=i;
	}
	int root(int a){
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	void merge(int a,int b){
		a=root(a);
		b=root(b);
		if(a==b) return;
		if(rank[b]>rank[a]) swap(a,b);
		par[b]=a;
		rank[a]+=rank[b];
	}
};
void  solve(){
	int n,m,x,y;
	cin>>n>>m;
	int  p[n+1];
	rep(i,1,n+1) cin>>p[i];
	dsu d(n);
	rep(i,0,m){
		cin>>x>>y;
		d.merge(x,y);
	}
	map<int,int> m1;
	rep(i,1,n+1){
		m1[p[i]]=i;
	}
	int ans=0;
	rep(i,1,n+1){
		if(d.root(i)==d.root(m1[i])) ans++;
	}
	cout<<ans<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
