#include <bits/stdc++.h>
using namespace std;
 
int digit(int n){
    int digitsum = 0;
    while(n){
        digitsum += n % 10;
        n = n / 10;
    }
    return digitsum;
}
 
int main(){
    int n;
    cin >> n;
    int ans = 1000000;
    for(int i = 1; i < n; i++){
        if(ans > digit(i) + digit(n-i)){
            ans = digit(i) + digit(n-i);
        }
    }
    cout << ans << endl;
    return 0;
}