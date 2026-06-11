#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,q;
	string s;
	// nyuryoku
	cin >> n >> q >> s;
	int l[q],r[q];
	for(int i=0;i<q;i++){
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	int sum[s.size()];
	sum[0] = 0;
	for(int i=1;i<n;i++){
		if(s[i-1] == 'A' && s[i] == 'C'){
			sum[i] = sum[i-1] + 1;
		}else{
			sum[i] = sum[i-1];
		}
	}
	// keisan
	for(int i=0;i<q;i++){
		cout << sum[r[i]] - sum[l[i]] << endl;
	}
	// syutsuryoku
}