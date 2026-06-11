#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int ans = a[0];
	// keisan
	while(a[n-2] != 0){
		int flag = 0;
		int s;
		for(int i=0;i<n;i++){
			if(flag){
				a[i] = a[i]%s;
			}else{
				if(a[i] != 0){
					s = a[i];
					flag = 1;
				}
			}
		}
		ans = s;
		sort(a,a+n);
	}
	// syutsuryoku
	cout << ans << endl;
}