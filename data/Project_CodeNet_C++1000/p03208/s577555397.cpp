#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

int H[110];
int h[110];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,k;cin>>n>>k;

	vector<int> h(n);

	rep(i,n){
		cin>>h[i];
	}

	sort(h.begin(),h.end());

	ll ans =1000000000000;
	for(int i=0; i<n-(k-1); i++){
		ans = min(ans, (ll)h[i+(k-1)]-h[i]);
	}

	writeln(ans);




}

