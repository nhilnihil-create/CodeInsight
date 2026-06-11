#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main(){
	int n; cin >> n;
	if(n==25) cout << "Christmas";
	if(n==24) cout << "Christmas Eve";
	if(n==23) cout << "Christmas Eve Eve";
	if(n==22) cout << "Christmas Eve Eve Eve";
	cout << endl;
}