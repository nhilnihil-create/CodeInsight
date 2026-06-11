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
	ll a,b,k;cin>>a>>b>>k;
	for(int i = 0; i < k; i++) {
		if(i % 2 == 0){
			if (a % 2 == 1){
				a--;
			}
			a /= 2;
			b += a;
		}
		else{
			if(b % 2 == 1){
				b--;
			}
			b /= 2;
			a += b;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}