#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define FastIO cin.sync_with_stdio(false),cin.tie(NULL)

ll max(ll a, ll b){
    if(a>b) return a;
    return b;}

ll min(ll a, ll b){
    if(a<b) return a;
    return b;}

const ll MOD = 1e9 + 7, N = sqrt(1e13) + 1, INF = INT_MAX, M = 1e6;
#define val first
#define lst second
bool b[N];
std::vector<ll> pr;

int main(){
	//FastIO;
	

	int n, a, b;
	cin >> n >> a >> b;

	cout << min(n*a, b) << "\n";

	return 0;
}

