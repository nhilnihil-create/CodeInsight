#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    int now = 0;
    for (int i = 0; i < k; i++){
        if (now == 0){
            int tmp = a / 2;
            a = tmp;
            b += tmp;
            now = 1;
        }
        else {
            int tmp = b / 2;
            b = tmp;
            a += tmp;
            now = 0;
        }
    }
    cout << a << " " << b << endl;
}