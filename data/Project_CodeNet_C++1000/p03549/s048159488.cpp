#include <bits/stdc++.h>
using namespace std;

int main(){
	double N,M;
	cin >> N >> M;
	int ano = 100*(N-M);
	double pro = 0.5;
	for(int i=1; i<M; i++)pro *= 0.5;

	double ans = 0;
	double p = pro;
	for(int i=1; i<=1000; i++){
		ans += (M*1900+ano)*i*pro;
		pro *= (1-p);
	}

	cout << ans << endl;
}
