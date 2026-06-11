#include<bits/stdc++.h>
#include<string>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define mod (ll)(1e9+7)
#define nax (ll)(1e5)
#define INFL LLONG_MAX
#define NINFL LLONG_MIN
#define INF INT_MAX
#define disp(a,n,arr) for(int i=a;i<(ll)n;i++) cout << arr[i] << " "; cout << "\n";
#define check cout << "Working\n";
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
	FIO;
	int t = 1;
	//cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ll a = (s[0]-'0')*10 + s[1]-'0';
		ll b = (s[2]-'0')*10 + s[3]-'0';
		if(a <= 12 && a > 0 && b <= 12 && b > 0){
			cout << "AMBIGUOUS\n";
		}else if(a <= 12 && a > 0){
			cout << "MMYY\n";
		}else if(b <= 12 && b > 0){
			cout << "YYMM\n";
		}else cout << "NA\n";
	}


	return 0;
}
