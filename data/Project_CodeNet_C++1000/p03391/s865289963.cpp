/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;

int n ,a[N] ,b[N] ,mn=1e9+5 ;
bool is = 1 ;
int main(){
    scanf("%d",&n);
    long long ans = 0;
    for(int i=0;i<n;++i){
        scanf("%d%d",a+i,b+i);
        if(a[i]!=b[i]) is = 0 ;
        ans += b[i] ;
        if(a[i]>b[i]) mn = min(mn,b[i]) ;
    }
    if(is) return cout << 0,0 ;
    cout << ans - mn ;
    return 0;
}
