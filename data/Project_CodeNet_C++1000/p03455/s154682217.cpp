#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%s\n", (a * b) % 2 ? "Odd" : "Even");
}
