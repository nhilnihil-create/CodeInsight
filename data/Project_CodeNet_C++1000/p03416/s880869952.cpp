#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a; i < b + 1; i++){
        int c_1 = i / 10000;
        int c_2 = (i % 10000) / 1000;
        int c_3 = (i % 100) / 10;
        int c_4 = i % 10;
        if (c_1 == c_4 && c_2 == c_3){
            sum++;
        }
    }
    cout << sum << endl;
}