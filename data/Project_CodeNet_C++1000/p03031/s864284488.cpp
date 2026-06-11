#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, ans = 0;
	cin>> n>>m;
	int sw[n][m];
	vector<int> onoff(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sw[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int b;
			cin>>b;
			sw[b-1][i] = 1;
		}
	}
	vector<int> p(m);
	for(int i=0;i<m;i++){
		cin>>p[i];
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			onoff[j] = i&(1<<j);
			onoff[j]>>=j;
		}
		int cnt = 0;
		for(int k=0;k<m;k++){
			int tmpcnt = 0;
			for(int l=0;l<n;l++){
				if(sw[l][k] == 1&&onoff[l] == 1){
					tmpcnt++;
				};
			}
			if(tmpcnt%2 == p[k]) cnt++;
		}
		if(cnt == m) ans++;
	}
	cout<<ans<<endl;
}