#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
	int t = 0;
	while(n){
		t += n % 10;
		n /= 10;
	}
	if(t == 1){
		cout << 10 << endl;
    }
	else{
		cout << t << endl;
    }
}