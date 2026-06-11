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
const ll mod = 1000000007;
int n, a[200020], ans;

int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n;
	a[0]=-1;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>a[i-1]+1) return cout<<-1, 0;
		else if(a[i]<a[i-1]+1) ans+=a[i]-1;
	}
	cout<<n-1+ans;
}