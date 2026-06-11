#include <cstdio>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

const ll BASE = 1e9;

ll x[1010], y[1010];
string ans[1010];
int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%lld %lld", &x[i], &y[i]);
		x[i] += BASE;
		y[i] += BASE;
	}

	for(int i=1;i<n;i++) {
		if((x[0]^y[0])%2 != (x[i]^y[i])%2) {
			puts("-1");
			return 0;
		}
	}

	int add=0;
	if(!((x[0]^y[0])&1)) {
		add = 1;
	}

	vector<ll> ds;
	ds.push_back(BASE+add);
	ds.push_back(BASE);

	for(int i=0;i<=32;i++) {
		ds.push_back(1ll<<i);
	}
	
	for(int i=0;i<n;i++) {
		ll cx = x[i], cy = y[i];

		ans[i] = "";
		ans[i] += "LD";
		cx += add;
		
		for(int j=0;j<32;j++) {
			// carry
			if((cx+cy)&2) {
				if(cx&1) {
					ans[i]+="R";
				}
				else {
					ans[i]+="U";
				}
			}
			// carry x -> carry만들어야함
			else {
				if(cx&1) {
					ans[i] += "L";
					cx++;
				}
				else {
					ans[i] += "D";
					cy++;
				}
			}
			cx>>=1;
			cy>>=1;
		}


		if(cx&1) {
			ans[i] += "R";
			cx--;
		}
		else {
			ans[i] += "U";
			cy--;
		}
	}

	printf("%d\n", ds.size());
	for(int i=0;i<ds.size();i++) {
		printf("%lld ", ds[i]);
	}
	puts("");
	for(int i=0;i<n;i++) {
		// printf("x[i]:%lld, y[i]:%lld\n", x[i], y[i]);

		ll cx=0, cy=0;
		for(int j=0;j<ds.size();j++){
			if(ans[i][j]=='R')
				cx += ds[j];
			else if(ans[i][j]=='L')
				cx -= ds[j];
			else if(ans[i][j]=='U')
				cy += ds[j];
			else if(ans[i][j]=='D')
				cy -= ds[j];
		}
		// printf("cx:%lld, cy:%lld\n", cx+BASE, cy+BASE);
		printf("%s\n", ans[i].c_str());
	}
	return 0;
}

/*
3
-1000000000 -999999999
-999999999 -999999996
-999999997 -1000000000
*/