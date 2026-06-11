#include <cstdio>
#include <algorithm>
using namespace std;
int a, b;
int main() {
	scanf("%d%d", &a, &b);
	printf(a + b == 15 ? "+\n" : a * b == 15 ? "*\n" : "x\n");
}