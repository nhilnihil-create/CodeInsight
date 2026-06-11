#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	string s[2*n];
	for(int i=0; i<n; i++){
		cin >> s[i];
		s[i]+=s[i];
		s[n+i]=s[i];
	}

	int ans=0;
	for(int i=0; i<n; i++){
		bool flg=true;
		for(int x=0; x<n; x++){
			for(int y=0; y<n; y++){
				flg&=(s[i+x][y]==s[i+y][x]);
			}
		}
		if(flg) ans++;
	}
	cout << ans*n << endl;
	return 0;
}