#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, A, B;
	cin >> N >> A >> B;
	int ans = 0;;
	rep(i,N+1){
		int tmp = i;
		int res = 0;
		while(tmp){
			res += tmp%10;
			tmp /= 10;
		}
		if(A <= res && res <= B){
		   	ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
			

		










