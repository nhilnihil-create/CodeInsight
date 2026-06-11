#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string N;
	cin >> N;
	printf((N[0] == N[1] && N[0] == N[2]) || (N[1] == N[2] && N[1] == N[3]) ? "Yes\n" : "No\n");
	return 0;
}
