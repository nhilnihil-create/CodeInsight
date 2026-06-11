#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool ans = false;

    while(true){
        if(n%4==0 || n%7==0){
            ans = true;
            break;
        }
        else if(n - 7 >= 0) n -= 7;
        else if(n - 4 >= 0) n -= 4;
        else break;

        if(n==0){
             ans = true;
             break;
         }
    }

    if(ans) puts("Yes");
    else puts("No");
}