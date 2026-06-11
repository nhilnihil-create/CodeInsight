#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	if(abs(a-b)%2==1)
		cout << "Borys" << endl;
	else
		cout << "Alice" << endl;	
	return 0;
}
