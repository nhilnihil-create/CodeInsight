#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n , l[300005] = {} , r[300005] = {} , ans;
    string s;
    
    cin >> n;
    cin >> s;
    
    ans = n;
    
    for(int i=0 ;i<n ;i++ ){
        if(s[i] == 'E'){
            l[i+1]++;
        } else {
            r[i+1]++;
        }
        l[i+1] += l[i] , r[i+1] += r[i];
    }
    
    for(int i=1 ;i<=n ;i++ ){
        ans = min(ans , r[i-1] + l[n] - l[i]);
    }
    
    cout << ans << endl;
    return(0);
}