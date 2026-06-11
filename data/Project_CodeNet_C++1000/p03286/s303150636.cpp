#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string ans = "";
    if(n == 0) ans = '0';
    while(n != 0){
        if(n % 2 != 0){
            ans += '1';
            n--;
        }
        else{
            ans += '0';
        }
        n /= -2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}