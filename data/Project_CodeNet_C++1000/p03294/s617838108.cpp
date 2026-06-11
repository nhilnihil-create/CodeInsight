#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	int ans = 0;
	rep(i,N){
		int tmp;
		cin >> tmp;
		ans += tmp;
	}
	cout << ans - N << endl;

}












