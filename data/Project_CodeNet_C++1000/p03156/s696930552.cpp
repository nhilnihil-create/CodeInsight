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
	int n,a,b;cin >> n>>a>>b;
	vector<int> v(n);
	int ans1 =0;
	int ans2 =0;
	int ans3 =0;
	for(int i = 0; i < n; i++) {
		cin>>v[i];
		if (v[i] <= a){
			ans1++;
		}
		else if (v[i] > a && v[i] <= b){
			ans2 ++;
		}
		else{
			ans3++;
		}
	}
	cout << min(ans1,min(ans2,ans3)) << endl;

	return 0;
}