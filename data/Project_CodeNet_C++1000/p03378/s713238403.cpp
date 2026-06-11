#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n,m,x;
	cin >> n >> m >> x;
	int left = 0;
	rep(i,m){
		int xx;
		cin >> xx;
		if(xx<x) left++;
	}
	//cout << left << endl;
	cout << min(left,m-left) << endl;
	return 0;
}