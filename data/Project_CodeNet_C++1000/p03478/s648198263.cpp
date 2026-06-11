#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int f(int a){
	int ret = 0;
	while(a){
		ret += a%10;
		a /= 10;
	}
	return ret;
}

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		if(f(i) >= a && f(i) <= b) sum+= i;
	}
	cout << sum << endl;
}