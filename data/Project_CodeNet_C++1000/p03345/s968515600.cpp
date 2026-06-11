#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    long long limit = 1000000000000000000;

    long long a_temp, b_temp, c_temp;
    a_temp = a;
    b_temp = b;
    c_temp = c;
    
    if(k % 2 == 0){
        if(abs(a - b) > limit){
            cout << "Unfair" << endl;
            return 0;
        }
        cout << a - b << endl;
        return 0;
    }else{
        if(abs(a - b) > limit){
            cout << "Unfair" << endl;
            return 0;
        }
        cout << b - a << endl;
        return 0;
    }
}