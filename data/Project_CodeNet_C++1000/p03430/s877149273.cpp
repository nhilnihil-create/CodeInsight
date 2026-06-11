#include <bits/stdc++.h>

using namespace std;

int n, m;
char str[310];
int D[310][310][310];

int main() {
    int i, j, k, l;

    scanf("%s",str); n = strlen(str);
    scanf("%d",&m);
    for (l=0;l<n;l++) {
        for (i=0;i<n-l;i++) {
            j = i+l;
            for (k=0;k<=l+1;k++) {
                if (!l) {
                    D[i][j][k] = 1;
                    continue;
                }
                D[i][j][k]=max({D[i+1][j][k],D[i][j-1][k],D[i+1][j-1][k]+2*(str[i]==str[j])});
                if (k) D[i][j][k]=max({D[i][j][k],D[i+1][j-1][k-1]+2,D[i][j][k-1]});
            }
        }
    }
    printf("%d\n",D[0][n-1][m]);

    return 0;
}
