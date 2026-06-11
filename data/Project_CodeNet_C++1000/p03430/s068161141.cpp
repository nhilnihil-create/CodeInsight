#include <bits/stdc++.h>

const int maxn = 310;

using namespace std;

int n,K,f[maxn][maxn][maxn];
string t;

int main() {
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    cin>>K;
    n= t.length();
    for (int i=n-1;i>=0;i--)
        for (int j=i;j<n;j++)
            for (int k=0;k<=K;k++) {
                    if (i==j) {
                        f[i][j][k] = 1;
                        continue;
                    }
                    if (i+1==j) {
                        f[i][j][k] = ((t[i] == t[j] || k>0) ? 2 : 1);
                        continue;
                    }
                    f[i][j][k] = max(f[i+1][j][k], f[i][j-1][k]);
                    if (t[i]==t[j]) f[i][j][k] = max(f[i][j][k], f[i+1][j-1][k] + 2);
                    else if (k>0) f[i][j][k] = max(f[i][j][k], f[i+1][j-1][k-1] +2);
            }
    cout<<f[0][n-1][K]<<endl;
}

