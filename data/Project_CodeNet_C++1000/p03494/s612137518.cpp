#include <bits/stdc++.h>
using namespace std;

int counter(int num){
    int count = 0;
    while(num % 2 == 0){
        num /= 2;
        count++;
    }
    return count;
}

int main(){

    long  a, b;
    int count = 0;
    int res = 0xFFFF;

    cin >> a;
    
    for(int i = 0; i < a; i++){
        cin >> b;
        if(b % 2 != 0){
            res = 0;
            cout << res << endl;
            return 0;
        } else {
            int temp = counter(b);
            if(res > temp){
                res = temp;
            }
        }
    }

    cout << res << endl;
}