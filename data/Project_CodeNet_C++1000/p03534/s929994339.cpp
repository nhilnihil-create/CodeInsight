#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
 
#pragma comment(linker, "/STACK:336777216")  
 
using namespace std;

const int MAXN = 200000 + 10;
const int INF = 1000000000;

int N;
char S[MAXN];
int cnt[3];

void Work()
{
	scanf("%s", S);
	N = strlen(S);
	for (int i = 0; i < N; i ++)
		cnt[S[i] - 'a'] ++;
	
	sort(cnt, cnt + 3);
	printf((cnt[2] - cnt[0] <= 1) ? "YES\n" : "NO\n");
}

int main()
{
	Work();

	return 0;
}
