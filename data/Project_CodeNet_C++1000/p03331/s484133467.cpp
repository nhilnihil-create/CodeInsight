#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = n;
    for(int i=1; i<n; i++){
        int a = i;
        int b = n-i;

        int dsum = 0;
        while(a > 0){
            dsum += a % 10;
            a /= 10;
        }  
        while(b > 0){
            dsum += b % 10;
            b /= 10;
        }
        ans = min(ans, dsum);      
    }
    cout << ans << endl;
    return 0;
}