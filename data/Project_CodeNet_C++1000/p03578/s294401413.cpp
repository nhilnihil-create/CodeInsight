#include <bits/stdc++.h>
using namespace std;

const int maxN = 200020;

int n, m;
int A[maxN], B[maxN];

int main (){
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", A + i); sort(A, A + n);
	scanf("%d", &m);
	for(i = 0; i < m; ++i) scanf("%d", B + i); sort(B, B + m);
	for(i = j = 0; j < m; ++j){
		for(; i < n && A[i] < B[j]; ++i);
		if(i < n && A[i] == B[j]) ++i;
		else break;
	}
	puts(j == m ? "YES" : "NO");
	return 0;
}
