#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	ll x[1005],y[1005];

	int mod = -1;

	for (int i = 0;i < n;i++){
		cin >> x[i] >> y[i];
		if(i == 0) mod = abs(x[i]+y[i])%2;
		else if(mod != abs(x[i]+y[i])%2){
			cout << -1 << endl;
			return 0;
		}
	}

	vector<string> w(n,""),p(n,"");

	if(mod == 0){
		cout << 32 << endl << 1 << " ";
		for (int i = 0;i <= 30;i++){
			cout << (1<<i) << " ";
		}
		cout << endl;
		for (int i = 0;i < n;i++){
			p[i] += "R";
			x[i] -= 1;
		}
	}else{
		cout << 31 << endl;
		for (int i = 0;i <= 30;i++){
			cout << (1<<i) << " ";
		}
		cout << endl;
	}

	for (int i = 0;i < n;i++){
		for (int j = 30;j >= 0;j--){
			ll d  = 1 << j;
			ll nx = d-1;
			//cout << nx << endl;
			if(abs(x[i]-d)+abs(y[i]) <= nx){
				w[i] = "R" + w[i];
				x[i] -= d;
			}else if(abs(x[i]+d)+abs(y[i]) <= nx){
				w[i] = "L" + w[i];
				x[i] += d;
			}else if(abs(x[i])+abs(y[i]+d) <= nx){
				w[i] = "D" + w[i];
				y[i] += d;
			}else if(abs(x[i])+abs(y[i]-d) <= nx){
				w[i] = "U" + w[i];
				y[i] -= d;
			}
		}
		//reverse(w[i].begin(),w[i].end());
		cout << p[i] + w[i] << endl;
	}
	
	return 0;

}
