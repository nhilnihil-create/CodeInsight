#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define N_MAX 110

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	int N; char str[3][N_MAX];
	scanf("%d", &N);
	for (int i = 0; i < 3; i++){
		scanf("%s", str[i]);
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++){
		if (str[0][i] != str[1][i] && str[1][i] != str[2][i] && str[2][i] != str[0][i]){
			cnt += 2;
		}
		else if (str[0][i] == str[1][i] && str[1][i] == str[2][i] && str[2][i] == str[0][i]){

		}
		else{
			cnt++;
		}
	}

	printf("%d", cnt);

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}