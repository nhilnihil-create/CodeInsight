#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b; cin >> a >> b;
	int d = b - a;
	int t = (d*(d-1))/2;
	printf("%d\n", t - a);
	return 0;
}