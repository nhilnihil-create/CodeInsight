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
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	for(int i = 0; i < n; i++) {
		cin>>b[i];
	}
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		if (b[i] >= a[i]){
			sum += (b[i] - a[i]) / 2;
		}
		else{
			sum += (b[i] - a[i]);
		}
	}
	if (sum >= 0)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}