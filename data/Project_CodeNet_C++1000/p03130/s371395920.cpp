#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	rep(i,6){
		int x;
		cin >> x;
		if(x==1) a++;
		if(x==2) b++;
		if(x==3) c++;
		if(x==4) d++;
	}
	if(a==1&&b==2&&c==2&&d==1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

