#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, A, B;
	cin >> N >> A >> B;
	int tot = 0;
	rep(i,N+1){
		int tmp = 0;
		int k = i;
		rep(j,5){
			tmp += k%10;
			k /= 10;
		}
		if (A<=tmp && tmp<=B) tot += i;
	}
	cout << tot << endl;
	return 0;
}
