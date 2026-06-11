#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAX 200000

int d[MAX+1][20];

bool check(int l, int r){
	bool flg=true;
	for(int i=0; i<20; i++){
		if(d[r][i]-d[l-1][i]>1) flg=false;
	}
	return flg;
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		for(int j=0; j<20; j++){
			d[i+1][j]=d[i][j];
			if(a%2==1) d[i+1][j]++;
			a/=2;
		}
	}

	int r=1;
	ll ans=0;
	for(int l=1; l<=n; l++){
		while(r<=n && check(l, r)) r++;
		ans+=r-l;
	}
	cout << ans << endl;
	return 0;
}