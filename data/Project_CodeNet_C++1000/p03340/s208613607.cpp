/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;

int n ,a[N] ,cnt[N][22] ;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        vector<int> v ,cur ;
        for(int j=0;j<22;++j){
            cnt[i][j] = cnt[i-1][j] ;
            if((1<<j)>a[i]) continue ;
            if(a[i] & (1<<j)) ++cnt[i][j] ;
        }
    }
    long long ans = 0 ;
    for(int i=0;i<n;++i){
        int st=i+1 ,en=n ;
        while(st<en){
            int mid = (st+en+1)/2 ;
            int mx = 0 ;
            for(int j=0;j<22 && mx<2;++j) mx = max(mx,cnt[mid][j]-cnt[i][j]);
            if(mx<2) st=mid ;
            else en=mid-1;
        }
        ans += st-i ;
    }
    cout << ans;
    return 0;
}
