#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N, H, W;
    cin >> N >> H >> W;
  	cout << (N-H+1)*(N-W+1) <<endl;
    return 0;
}