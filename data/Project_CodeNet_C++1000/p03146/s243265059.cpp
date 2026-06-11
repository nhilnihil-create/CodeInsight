#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;
const int mx = 10000000;
vector<int> a(mx);

int clllats(int N){
	if(N%2==0) return N / 2;
	else return 3 * N + 1;
}

int main(){
	cin >> a[0];
	for(int i = 1;i<mx;i++) {
		a[i] = clllats(a[i-1]);
	}
	int ans = mx;
	rep(i,mx-2){
		int tmp = 100;
		for(int j = i + 1;j <= mx -1; j++){

			if(a[i] == a[j]){
				tmp = j + 1;
				ans = min(ans, tmp);
				break;
			}
		}
	}	
	cout << ans << endl;
	return 0;
}











