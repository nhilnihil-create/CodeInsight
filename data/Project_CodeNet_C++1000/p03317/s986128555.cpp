#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<typeinfo>
#include<queue>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int>a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	if((N-1)%(K-1)==0)cout << (N-1) / (K - 1);
	else cout<< (N - 1) / (K - 1)+1;
}