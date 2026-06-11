#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
    scanf("%d %d", &n, &k);
	printf("%d", n-k+1);
	return 0;	
}