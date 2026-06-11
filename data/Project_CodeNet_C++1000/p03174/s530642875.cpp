#include <bits/stdc++.h>

using namespace std;

long long n;
long long A[50][50],F[50][1<<21];
long long mat(int i,int used)
{

    if (i>n) return 1;
    if (F[i][used]!=-1) return F[i][used];
    long long res=0;

    for (int z=1; z<=n; ++z){
        if (A[i][z]==0 || ((used>>z)&1)) continue;
            res=(res + mat(i+1,used | (1<<z)))%1000000007;
    }

    return F[i][used]=res;

}


int main()
{
    //freopen("matching.inp", "r", stdin);
    //freopen("matching.out", "w", stdout);
    cin>>n;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            cin>>A[i][j];
        }
    }
    for (int i=1; i<=25; ++i)
        for (int j=1; j<=(1<<21);++j)
            F[i][j]=-1;
    cout<<mat(1,1);

    return 0;
}
