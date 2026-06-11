#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,k;
	cin >> a >> b >> k;
	int counts = 0;
	int hani = max(a,b);
	for(int i = hani; i > 0; i--){
		if(a%i == 0 && b%i == 0) counts++;
		if(counts == k){
			cout << i << endl;
			return 0;
		}
		}
}