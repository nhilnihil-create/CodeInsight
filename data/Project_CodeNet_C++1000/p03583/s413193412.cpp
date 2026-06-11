#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll N;cin>>N;
	for(ll h = 1; h <= 3500; h++) {
		for(ll n = 1; n <= 3500; n++) {
			if ((4 * h * n - N * n - N * h) > 0 && (N * h * n) %(4 * h * n - N * n - N * h) == 0){
				cout << h << ' ' << n << ' ' << (N * h * n)  / (4 * h * n - N * n - N * h) << endl;
				return 0;
			}
		}
	}
	return 0;
}