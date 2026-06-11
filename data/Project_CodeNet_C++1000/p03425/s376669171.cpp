#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> c(5);
	rep(i, n){
		string s;
		cin >> s;
		if(s[0] == 'M'){
			c[0]++;
		}else if(s[0] == 'A'){
			c[1]++;
		}else if(s[0] == 'R'){
			c[2]++;
		}else if(s[0] == 'C'){
			c[3]++;
		}else if(s[0] == 'H'){
			c[4]++;
		}
	}
	lli ans = 0;
	rep(i, 5){
		rep(j, 5){
			rep(k, 5){
				if(i == j || j == k || k == i) continue;
				ans+=c[i]*c[j]*c[k];
			}
		}
	}
	cout << ans/6 << endl;
	return 0;
}
