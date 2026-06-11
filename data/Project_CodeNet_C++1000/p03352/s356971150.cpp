#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	int x;
	cin >> x;
	int out = 1;
	for(int i = 2; i < x; i++){
		if(x < i * i) break;
		int num = i;
		while(x > num){
			num *= i;
		}
		out = max(out, x < num ? num / i : num);
	}
	cout << out << endl;
}
