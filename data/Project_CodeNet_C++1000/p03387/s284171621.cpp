#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for(int i =0 ; i < n; ++i)
#define pii pair < int, int >
typedef vector<int> vi;
typedef   long long ll;
const int mod =1e9+7;




void solve(){
	vi v(3);
	cin>>v[0]>>v[1]>>v[2];
	int cnt=0;
	while(true){
		if(v[0]==v[1] && v[1]==v[2])break;
		sort(all(v));
		if(v[0]<v[2] && v[1]<v[2])v[0]++,v[1]++;
		else if(v[0]<v[1])v[0]+=2;
		cnt++;
	}
	cout<<cnt;

}


int main(){
	Red;
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}