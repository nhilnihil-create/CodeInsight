#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	double ans = 0;
	for (int i = 0; i < N; i++){
		string x, u;
		cin >> x >> u;

		if (u == "JPY"){
			ans += atoi(x.c_str());
		} else {
			ans += atof(x.c_str()) * 380000.f;
		}
	}

	cout << fixed << setprecision(5) << ans << endl;
	return 0;
}
