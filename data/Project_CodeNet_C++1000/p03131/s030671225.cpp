#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int k, a, b;
    cin >> k >> a >> b;

    long long int ans = 0;
    if(b - a <= 2) ans = k+1;
    else{
        if(k >= a-1){
            ans = a + (k-(a-1)) / 2 * (b-a);
            if((k-(a-1)) % 2 == 1) ans += 1;
        }
        else ans = k+1;
    }
    cout << ans << endl;
    return 0;
}