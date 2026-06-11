#include <bits/stdc++.h>
using namespace std;

int ecd(int a, int b){
    if (b == 0){
        return a;
    }
    return ecd(b, a%b);
}

int main(){
    int n, x;
    cin >> n >> x;

    int sign = 0;
    for (int i = 0; i<n; i++){
        int a;
        cin >> a;
        a = abs(x-a);

        if (sign == 0){
            sign = a;
            continue;
        }

        if (sign > a){
            sign = ecd(sign, a);
        }else if (a > sign){
            sign = ecd(a, sign);
        }else if (a == sign){
            sign = a;
        }
    }

    cout << sign << endl;
}