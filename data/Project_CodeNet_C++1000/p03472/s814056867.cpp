#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int main() {
    int n,h ;
    cin >> n >> h ;
    int a[n],b[n] ;
    int amax = -1 ;

    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] ;
        amax = max(a[i],amax) ;        
    }

    int ans = 2147483647 ;
    sort(b,b+n) ;
    reverse(b,b+n) ;

    for(int i= 0 ; i<=n;i++){
        int cnt = 0 ;
        if(i>0) h-= b[i-1] ;
        if(h>0) cnt = (h+amax-1)/amax ;
        ans = min(cnt+i,ans) ;
    }

    cout << ans << endl ;
    return 0 ;
}
