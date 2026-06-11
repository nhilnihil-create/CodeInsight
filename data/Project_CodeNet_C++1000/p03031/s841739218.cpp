#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > sw(m+1,vector<int>(n+1,-1));
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> sw[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		cin >> sw[i][0];
	}
	int ans = 0;
	for(int s=0;s<(1<<n);s++){
		bool flag = true;
		for(int i=1;i<m+1;i++){
			int cnt = 0;
			for(int j=1;j<n+1;j++){
				if(sw[i][j] == -1) continue;
				if(s>>(sw[i][j]-1)&1) cnt++;
			}
			if(cnt%2 != sw[i][0]) flag = false;
		}
		if(flag) ans++;
	}
	cout << ans << endl;
}
