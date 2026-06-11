#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    vector <int> n(4);
    vector <char>s(3);

    cin >> num;

    n[3] = num / 1000; num = num % 1000;
    n[2] = num / 100;  num = num % 100;
    n[1] = num / 10;   num = num % 10;
    n[0] = num;
    // cout << n[3] << n[2] << n[1] << n[0] <<  endl;
    int sum = 0;

    for(int i = 0; i < 8; ++i){
        sum = n[3];
        for(int j = 0; j < 3; ++j){
            if((i >> j) & 1){
                sum += n[2 - j]; 
                s[2-j] = '+';
            }else{
                sum -= n[2 - j];
                s[2-j] = '-';
            }
        }
        if(sum == 7){
            cout << n[3] << s[2] << n[2] << s[1] << n[1] << s[0] << n[0] << "=7" <<endl;
            return 0;
        }
    }
}