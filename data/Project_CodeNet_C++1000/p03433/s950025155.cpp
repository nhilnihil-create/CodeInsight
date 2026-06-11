#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int N, A;
	scanf("%d %d", &N, &A);
	printf(N % 500 <= A ? "Yes\n" : "No\n");

	return 0;
}
