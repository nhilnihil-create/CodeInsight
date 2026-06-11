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
const ll mod = (int)1e9 + 7;
int n, k;
 
int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n>>k;
	if(n==1){
		if(k==0) return cout<<"0 0 1 1", 0;
		else return cout<<-1, 0;
	}
	if(k>=(1<<n)) return cout<<-1, 0; 
	for(int i=0; i<(1<<n); i++){
		if(i!=k) cout<<i<<" ";
	}
	cout<<k<<" ";
	for(int i=0; i<(1<<n); i++){
		if((1<<n)-1-i!=k) cout<<(1<<n)-1-i<<" ";
	}
	cout<<k;
}