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
	int ans = INF;
	for(int i = 1; i < n; i++) {
		int b = n - i;
		int tmp = 0;
		string A = to_string(i);
		string B = to_string(b);
		for(int i = 0; i < A.size(); i++) {
			tmp += A[i] - '0';
		}
		for(int i = 0; i < B.size(); i++) {
			tmp += B[i] - '0';
		}
		ans = min(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}