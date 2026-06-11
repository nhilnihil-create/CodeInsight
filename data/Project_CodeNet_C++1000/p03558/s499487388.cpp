#include <stdio.h>

bool b[11][100001], c[100001];
int p[100001];

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	int K;
	scanf("%d", &K);
	for (int i=0;i<K;i++) p[i] = i;
	for (int i=0;i<K;i++) p[find(i)] = find((i*10)%K);

	b[0][0] = 1;
	for (int i=0;;i++){
		for (int j=0;j<K;j++) c[j] = 0;
		for (int j=0;j<K;j++) if (b[i%11][j]) c[find(j)] = 1;
		for (int j=0;j<K;j++) if (c[find(j)]){
			b[i%11][j] = 1;
			for (int v=1;v<10;v++){
				b[(i+v)%11][(j*10+v)%K] = 1;
			}
		}
		if (i && b[i%11][0]){ printf("%d\n", i); break; }
		for (int j=0;j<K;j++) b[i%11][j] = 0;
	}

	return 0;
}