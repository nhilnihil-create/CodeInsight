#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL A, B, C, K;
	cin >> A >> B >> C >> K;
	if(abs(A-B) > 1000000000000000000){
		cout << "Unfair" << endl;
		return 0;
	}
	LL ans;
	if(K%2==1) ans = (A-B) * (-1);
	else ans = A - B;
	cout << ans << endl;

}











