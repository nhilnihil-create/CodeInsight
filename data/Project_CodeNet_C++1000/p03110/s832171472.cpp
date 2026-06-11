#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	double ans = 0;
	rep(i,n){
		double u;
		cin >> u;
		string s;
		cin >> s;
		if(s == "JPY"){
			ans += u;
		}else{
			ans += 380000.000*u;
		}
	}
	printf("%.10f", ans);
    return 0;
}

