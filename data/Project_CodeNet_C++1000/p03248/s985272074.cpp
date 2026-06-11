#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int mxn = 1e5;
int cnt1[mxn+2],cnt2[mxn+2];

void solve(){
	string s;
	cin >> s;
	int n = s.length();
	if(s[n-1]=='1'){
		cout << -1 << endl;return;
	}
	if(n==2){
		if(s[0]=='1')
			cout << "1 2" << endl;
		else
			cout << -1 << endl;return;
	}
	for(int i =0;i<n/2;i++){
		if(s[i] != s[n-2-i]){
			cout << -1 << endl;return;
		}
	}
	if(s[0]=='0'){
		cout << -1 << endl;return;
	}
	int cur = 1;
	int nxt = 2;
	for(int i =0;i<n-1;i++){
		cout << cur << " " << nxt << endl;
		if(s[i]=='1'){
			cur = nxt;nxt++;
		}
		else{
			nxt++;
		}
	}


}

int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	// int t;cin >> t;while(t--)
		solve();
}
