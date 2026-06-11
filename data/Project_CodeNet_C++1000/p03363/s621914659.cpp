#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n , i;
    long long a[200001] , s[200001] , ans = 0 , rCr , x , pin;

    cin >> n;
    for(i=1 ;i<=n ;i++ ){
        cin >> a[i];
    }

    s[0] = 0;
    
    for(i=1 ;i<=n ;i++ ){
        s[i] = s[i-1] + a[i];
    } 

    sort(s , s + (n + 1));

    i = 0 ;
    while(i < n){
        if(s[i] == s[i+1]){
            pin = i;
            i = i + 1;
            x = 1;
            while(s[i] == s[pin] && i <= n){
                i++;
                x++;
            }
            ans += (x * (x - 1)) / 2;
        } else {
            i++;
        }
    }

    cout << ans << endl;

    return (0);
}