#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n , k , kind=0 , a , ans = 0;
    int num[200005];
    
    cin >> n >> k;
    for(int i=0 ;i<=n ;i++ ){
        num[i] = n+1;
    }
    
    for(int i=0 ;i<n ;i++ ){
        cin >> a;
        if(num[a] == n+1){
            kind++;
            num[a] = 1;
        } else {
            num[a] ++;
        }
    }
    
    sort(num , num+(n+1));
    for(int i=0 ;i<kind-k ;i++ ){
        ans += num[i];
    }
    
    cout << ans << endl;
    
    return(0);
}