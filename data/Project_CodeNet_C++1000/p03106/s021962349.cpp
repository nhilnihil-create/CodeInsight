#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,k;
	cin >> a >> b >> k;

	int cnt = 0;
	int i = max(a,b);
	while(cnt!=k){
		if(a%i==0 && b%i==0) cnt++;
		i--;
	}

	cout << i+1 << endl;
	return 0;
}