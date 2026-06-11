#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=310;
char s[N];
int f[N][N][N];
inline int solve(int l,int r,int k) {
    if(l>r) return 0;
    if(l==r) return 1;
    if(f[l][r][k]!=-1) return f[l][r][k];
    int &ans=f[l][r][k];
    ans=max(solve(l+1,r,k),solve(l,r-1,k));
    if(s[l]==s[r]) ans=max(ans,solve(l+1,r-1,k)+2);
    else if(k) ans=max(ans,solve(l+1,r-1,k-1)+2);
    return ans;
}
int main() {
    int k;
    memset(f,-1,sizeof(f));
    scanf("%s%d",s+1,&k);
    cout<<solve(1,strlen(s+1),k);
    return 0;
}