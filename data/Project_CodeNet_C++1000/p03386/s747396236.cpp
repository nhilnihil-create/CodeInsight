#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int a, b, k;

int main(void){
	cin >> a >> b >> k;
	for(int i = a; i <= b; i++){
		if(i < a+k || i > b-k) cout << i << endl;
	}
	return 0;
}
