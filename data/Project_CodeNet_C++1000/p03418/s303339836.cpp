#include <iostream>
#include <string> 
#include <iomanip>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;






int main()
{
	int N, K;
	cin >> N >> K;

	long long count = 0;


	for (int b = K+1; b <= N;b++) {
		count += N / b *max(b - K, 0);
		count += max(0, N % b + 1 - K);
	}

	if (K == 0) {
		count -= N;
	}

	cout << count;
    return 0;
}