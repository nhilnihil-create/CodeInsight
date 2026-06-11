#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <ctime>
#include <map>
#include <algorithm>
#include <cmath>
#define MAXN 200005
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ba 823
#define mo 974711
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;

int N,A[100005];
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; ++i) scanf("%d",&A[i]);
	sort(A + 1,A + N + 1);
	printf("%d ",A[N]);
	double T = A[N] / 2.0;
	int t = 1;
	for(int i = 2 ; i <= N ; ++i) {
		if(fabs(A[i] - T) < fabs(A[t] - T)) t = i;
	}
	printf("%d\n",A[t]);
    return 0;
}