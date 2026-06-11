#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int f[n][5][2];
	int p[n][11];
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<2;k++){
				cin >> f[i][j][k];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=10;j++){
			cin >> p[i][j];
		}
	}
	long long ans=-1000000000000;
	for(int bit=1;bit<(1<<10);bit++){
		long long com=0;
		vector<int>a(10,0);
		for(int i=0;i<10;i++){
			if(bit&(1<<i)) a[i]=1;
		}
		vector<int>count(n,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				for(int k=0;k<2;k++){
					if(f[i][j][k]==1&&a[j*2+k]==1) count[i]++;
				}
			}
		}
		for(int i=0;i<n;i++){
			com+=p[i][count[i]];
		}
		ans=max(ans,com);
	}
	cout << ans << endl;
}
