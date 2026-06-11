#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n;
int a[101010];
void solve(){
	cin >> n;
	int l = 0, r = n;
	cout << 0 << endl;
	string s;
	cin >> s;
	if(s == "Vacant") return;
	if(s == "Male") a[0] = 1;
	if(s == "Female") a[0] = 2;
	
	while(1){
		int c = (l+r)/2;
		cout << c << endl;
		cin >> s;
		if(s == "Vacant") return;
		if(s == "Male") a[c] = 1;
		if(s == "Female") a[c] = 2;
		
		if((c-l)%2 ^ a[c]==a[l]){
			l = c;
		}
		else{
			r = c;
		}
	}
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
