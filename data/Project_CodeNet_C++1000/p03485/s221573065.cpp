#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

int main(){
	int a, b;
	cin >> a >> b;

	auto x = div(a+b, 2);

	if(x.rem){
		cout << x.quot +1 <<endl;
	}else{
		cout << x.quot << endl;
	}
}
