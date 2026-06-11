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
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(),a.end());
	int cnt = 0;
	while(a[0]<a[1]){
		a[0]+=2;
		cnt++;
	}
	sort(a.begin(),a.end());
 	if(a[0]==a[1]){
		cout << a[2] - a[0] + cnt << endl;
	}else{
		while(a[1]<a[2]){
			cnt++;
			a[0]++;
			a[1]++;
		}
		if((a[2]-a[0])%2==0) cout << cnt + (a[2]-a[0])/2 << endl;
		else cout << cnt+1+(a[2]+1-a[0])/2 << endl;
	}
 	return 0;
}