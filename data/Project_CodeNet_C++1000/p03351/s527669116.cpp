#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int a, b, c, d;
	int d_ab, d_bc, d_ac;
	cin >> a >> b >> c >> d;
	d_ab = fabs(a - b);
	d_bc = fabs(b - c);
	d_ac = fabs(a - c);
	if(d_ab <= d && d_bc <= d || d_ac <= d){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	return 0;
}