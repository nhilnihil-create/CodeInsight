#include <bits/stdc++.h>
using namespace std;

int exp(int a, int b);

int main(){

    int x;
    cin >> x;

    int ans = 0, buf = 0;
    int a, b = 2;
    int temp;

    for (a=2; a<x; a++){
        temp = exp(a, b);

        while (temp <= x){
            buf = temp;
            b++;
            temp = exp(a, b);
//            cout << buf << endl;  // debug
        }
        b = 2;
        ans = max(buf, ans);
    }

    if (ans != 0) cout << ans << endl;
    else cout << 1 << endl;
    return 0;
}

int exp(int a, int b){

    if (b == 0) return 1;

    return a*exp(a, b-1);
}