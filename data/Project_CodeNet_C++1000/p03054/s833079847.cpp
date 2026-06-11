#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

using namespace std;

typedef long long int lli;

int gcd(int a, int b){
	return b != 0 ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
	return a*b / gcd(a, b);
}

#define N_MAX 200000
#define MOD 1000000007

int N;
bool func(int width, int pos, char *S, char *T)
{
	int left = 1, right = width;

	for (int i = N - 1; i >= 0; i--){
		if ('L' == T[i]){
			right = min(width, right + 1);
		}
		else if ('R' == T[i]){
			left = max(1, left - 1);
		}

		if ('L' == S[i]){
			left++;
		}
		else if ('R' == S[i]){
			right--;
		}
		if (left > right){
			return false;
		}
	}

	if (left <= pos && pos <= right){
		return true;
	}
	return false;
}

void change(char *S)
{
	for (int i = 0; i < N; i++){
		if ('L' == S[i]){
			S[i] = 'U';
		}
		else if ('R' == S[i]){
			S[i] = 'D';
		}
		else if ('U' == S[i]){
			S[i] = 'L';
		}
		else if ('D' == S[i]){
			S[i] = 'R';
		}
	}

	return;
}

void solv()
{
	int H, W; scanf("%d%d%d", &H, &W, &N);
	pair<int, int> start; scanf("%d%d", &start.first, &start.second);
	char S[N_MAX + 10], T[N_MAX + 10]; scanf("%s%s", S, T);

	if (!func(W, start.second, S, T)){
		printf("NO");
		return;
	}

	change(S); change(T);
	if (!func(H, start.first, S, T)){
		printf("NO");
		return;
	}

	printf("YES");
	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}