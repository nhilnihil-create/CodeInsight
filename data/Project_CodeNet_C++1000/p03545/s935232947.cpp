#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main() {
    int abcd;
    cin >> abcd;

    for(int i=0;i<(1<<3);i++){
        int result=0;
        int x=abcd;
        string ans="";
        for(int j=1;j<(1<<3);j*=2){
            ans =  to_string(x % 10)+ ans;
            if(i&j){
                result += x % 10;
                ans =  '+' + ans;
            }else{
                result -= x % 10;
                ans =  '-' + ans;
            }
            x /= 10;
        }
        result += x;
        ans =  to_string(x)+ ans + "=7";
        if(result == 7){
            cout << ans;
            break;
        }

    }


} 