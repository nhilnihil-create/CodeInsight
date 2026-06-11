#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,P[100100],D[100100];
int find(int x)
{
    if (x != P[x]) {
        int r = P[x];
        P[x] = find(P[x]);
        D[x] += D[r];
    }
    return P[x];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) P[i] = i;

    for (int i=0; i<m; i++) {
        int l,r,d; scanf("%d %d %d",&l,&r,&d);
        int L = find(l);
        int R = find(r);
        if (L != R) {
            P[R] = L;
            D[R] = d + D[l] - D[r];
        } else {
            if (D[r] - D[l] != d) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
