//daddy's back in town, back to rolling the damn hash yoooo babeeeeees//
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define x first
#define y second
#define pi pair <int, int>
#define vi vector <int>
#define L nod<<1
#define R ((nod<<1)|1)
#define int ll
const ll mod = 998244353;
int n;
bool cnt[100010];
string s;
vi v;

int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>s;
	n=s.size();
	for(int i=1; i<=n; i++) cnt[i]=(s[i-1]=='1');
	for(int i=1; i<=n; i++){
		if(cnt[i]){
			if(cnt[n-i]==0) return cout<<-1, 0;
		}
	}
	if(cnt[1]==0 || cnt[n-1]==0) return cout<<-1, 0;
	for(int i=1; i<=n; i++) if(cnt[i]) v.pb(i);
	for(int i=1; i<=v.size(); i++) cout<<i<<" "<<i+1<<"\n";
	int cur=v.size()+2;
	for(int i=2; i<=v.size(); i++){
		for(int j=1; j<=v[i-1]-v[i-2]-1; j++){
			cout<<i<<" "<<cur<<"\n";
			cur++;
		}
	}
}