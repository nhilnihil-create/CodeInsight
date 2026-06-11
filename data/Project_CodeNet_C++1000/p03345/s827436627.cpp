#include <bits/stdc++.h>
#define ll      long long int
#define INF2    ((ll)1e18)
#define pii     pair<ll,ll>
#define x       first
#define y       second
#define vi      vector<ll>
#define pb      push_back
#define sz(a)   (ll)((a).size())
#define all(x)  (x).begin(), (x).end()
#define FIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p){os<<"("<<p.x<<","<<p.y<<") "; return os;}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){for(auto i: v) os<<i<<" "; return os;}

const ll mxN = 1e5;
const ll mod = 1e9+7;

int main(){
    FIO;
	//freopen("input.txt", "r", stdin);
	ll a, b, c, k;
	cin>>a>>b>>c>>k;
	if(k%2==0) cout<<a-b;
	else cout<<b-a;
}


