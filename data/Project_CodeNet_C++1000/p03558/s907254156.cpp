#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using pll = pair<ll,ll> ;
const int INF = 1e9 ;
void chmin(int &a,int b){if(a>b) a = b ;}
void chmax(ll &a,ll b){if(a<b) a = b ;}
void YorN(bool a){cout << (a?"YES":"NO") << "\n" ;}

int main(){
	int n ; cin >> n ;
	while(n%2==0) n /= 2 ;
	while(n%5==0) n /= 5 ;
	vll a(n,INF) ;
	priority_queue<pll> q ;
	q.emplace(-1,1) ;
	while(!q.empty()){
		ll p = q.top().second%n ;
		ll cost = -q.top().first ;
		q.pop() ;
		if(a[p]!=INF) continue ;
		a[p] = cost ;
		q.emplace(-cost,p*10) ;
		if(p%10!=9) q.emplace(-cost-1,p+1) ;
	}
	cout << a[0] << endl ;
	// for(auto i:a) cout << i << " " ; cout << endl ;
}