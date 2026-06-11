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
	int n;cin>>n;
	vector<P> v;
	int cnt = 0;
	if (n % 2 == 0){
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if (i + j != n + 1){
					v.pb(mp(i,j));
					cnt++;
				}
			}
		}
	}
	else{
		for(int i = 1; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if (i + j != n){
					v.pb(mp(i,j));
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++) {
		cout << v[i].fs << " " << v[i].sc << endl;
	}
	return 0;
}