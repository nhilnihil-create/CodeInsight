#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
//#define ivorysi
#define MAXN 20005
#define eps 1e-8
#define mo 974711
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
const int64 MOD = 998244353;
int N;
int c = 0,ans[MAXN],S;

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    scanf("%d",&N);
    if(N == 3) puts("2 5 63");
    else if(N == 4) puts("2 5 20 63");
    else if(N == 5) puts("2 5 20 30 63");
    else {
	for(int i = 0 ; i <= 4999 ; ++i) {
	    ans[++c] = 6 * i + 2,ans[++c] = 6 * i + 3,ans[++c] = 6 * i + 4,ans[++c] = 6 * i + 6;
	}
	for(int i = 1 ; i <= N ; ++i) S = (S + ans[i]) % 6;
	if(S == 5) {
	    ans[6] = 6 * 4999 + 4;
	}
	else if(S == 3) {
	    ans[6] = 6 * 5000;
	}
	else if(S == 2){
	    ans[5] = 6 * 5000;
	}
	for(int i = 1 ; i <= N ; ++i) printf("%d%c",ans[i]," \n"[i == N]);
    }
    return 0;
}
