#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	double total = 0;
	while(n--){
		double x; string s;
		cin >> x >> s;
		if(s=="JPY") total += x;
		else total += 380000.0*x;
	}
	cout << fixed << setprecision(5) << total;
	return 0;
}