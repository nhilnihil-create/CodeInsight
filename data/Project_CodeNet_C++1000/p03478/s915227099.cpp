#include <bits/stdc++.h>
using namespace std;

int calc(int num){
    int res = 0;
    while(num > 9){
        res += num % 10;
        num /= 10;
    }
    res += num % 10;
    return res;
}

int main(){

    int n, a, b, x;
    int count = 0;
    long res = 0;

    cin >> n >> a >> b;

    for(int i = 1; i <= n; i++){
        int temp = calc(i);
        if(a <= temp && temp <= b){
            res += i;
        }
    }

    cout << res << endl;

}

