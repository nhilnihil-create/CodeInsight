#include <bits/stdc++.h>
using namespace std;
long long n,a,b;
void solve(){
    if(a+b>n+1||a*b<n){
        puts("-1");
        return ;
    }
    while(n>0){
        long long x=min(a,n-b+1);
        for(long long i=n-x+1;i<=n;i++)
            printf("%lld ", i);
        n-=x;
        b--;
    }
}
int main(){
    scanf("%lld%lld%lld",&n,&a,&b);
    solve();
    return 0;
}