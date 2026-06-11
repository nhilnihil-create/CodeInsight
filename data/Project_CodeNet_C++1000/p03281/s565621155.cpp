#include <bits/stdc++.h>


using namespace std;

int main(){
	int n;
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;i+=2) {
		int d=0;
		for(int j=1;j<=i;j++) {
			if(i%j==0) d++;
		}
		if(d==8) ans++;
	}
	printf("%d",ans);
	return 0;
}


