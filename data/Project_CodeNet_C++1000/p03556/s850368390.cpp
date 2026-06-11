#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool f(long long N) {
    long long r = (long long)floor(sqrt((long double)N));  // 切り捨てした平方根
    return (r * r) == N;
}

int main(){
	int n;
    cin >> n;
	for(int i = n;i >= 1;i--){
		if(f(i)){
			cout << i << endl;
			return 0;
		}
	}
}