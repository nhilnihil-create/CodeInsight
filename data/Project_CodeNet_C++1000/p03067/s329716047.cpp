#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int mi = min(a, b);
	int ma = max(a, b);
	if(mi < c && c < ma){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}