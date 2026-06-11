#include <cstdio>
#include <algorithm>
using namespace std;

int N;
long long D[100010];
int cnt[100010];
int ansu[100010], ansv[100010];
int idx[100010];
long long Dv[100010];

int bsrch(int ll, int rr, long long vv)
{
	int l=ll, r=rr;
	int m;
	while(l<r){
		m = (l+r)/2;
		if(D[idx[m]] >= vv){
			r = m;
		}
		else
			l = m+1;
	}
	return l;
}

bool cmp(int aa, int bb)
{
	return D[aa] < D[bb];
}

int solve()
{
	int i, j=0;
	int ii;
	for(i=0; i<N; i++)
		idx[i] = i;
	sort(idx, idx+N, cmp);
	for(ii=N-1; ii>0; ii--){
		i = idx[ii];
		int p = bsrch(0, ii, D[i]-(N-2-cnt[i]*2) );
		if(p>=ii || D[idx[p]]!=D[i]-(N-2-cnt[i]*2) )
			return 0;
		cnt[idx[p]] += cnt[i]+1;
		Dv[idx[p]] += Dv[i] + (cnt[i]+1);
		ansu[j] = idx[p];
		ansv[j] = i;
		j ++;
	}
	if(Dv[idx[0]] != D[idx[0]])
		return 0;
	for(i=0; i<N-1; i++){
		printf("%d %d\n", ansu[i]+1, ansv[i]+1);
	}
	return 1;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int i;
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%lld", &D[i]);
	if(solve() == 0)
		printf("-1\n");
	return 0;
}