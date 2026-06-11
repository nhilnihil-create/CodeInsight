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
void  solve(){
	int n,c;
	cin>>n>>c;
	int d[c+1][c+1];
	rep(i,1,c+1) rep(j,1,c+1) cin>>d[i][j];

	int C[n+1][n+1];
	rep(i,1,n+1) rep(j,1,n+1) cin>>C[i][j];
	map<int,vector<int>> m1;
	rep(i,1,n+1) rep(j,1,n+1) m1[(i+j)%3].push_back(C[i][j]);
	vector<pair<int,int>> v1,v2,v3;
	rep(f,1,c+1){
			int sum=0;
			for(auto i:m1[0]){
				sum+= d[i][f];
			}
			v1.push_back({sum,f});
	}
	rep(f,1,c+1){
			int sum=0;
			for(auto i:m1[1]){
				sum+= d[i][f];
			}
			v2.push_back({sum,f});
	}
	rep(f,1,c+1){
			int sum=0;
			for(auto i:m1[2]){
				sum+= d[i][f];
			}
			v3.push_back({sum,f});
	}
	sort(all(v1));
	sort(all(v2));
	sort(all(v3));
	int ans=INT_MAX;
	rep(i,0,3){
		rep(j,0,3){
			rep(k,0,3){
				if(v1[i].s!=v2[j].s && v1[i].s!=v3[k].s && v3[k].s!=v2[j].s) ans=min(ans,v1[i].f+v2[j].f+v3[k].f);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
