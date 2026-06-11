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
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int tmp = a[0];
	int cnt = 1;
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(tmp == a[i]){
			cnt++;
		}
		else{
			tmp = a[i];
			ans += (cnt / 2);
			cnt = 1;
		}
	}
	ans += (cnt /2);
	cout << ans << endl;
	return 0;
}