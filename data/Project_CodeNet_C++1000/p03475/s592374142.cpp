#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

const int mx = 510;
vector<int> c(mx),s(mx),f(mx);
int time(int now,int pos){
	int ret,st = s[pos];
	while(st < now){
		st += f[pos];
	}
	ret = st-now+c[pos];
	return ret;
}

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n-1; i++) cin >> c[i] >> s[i] >> f[i];
	vector<int> ans(n,0);

	for(int i = 0; i < n-1; i++){
		ans[i] += s[i];
		for(int j = i; j < n-1; j++){
			ans[i] += time(ans[i],j);
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
	return 0;
}