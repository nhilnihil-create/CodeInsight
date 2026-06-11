#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int count = 0;
    for(int i = a ; i < b + 1 ; i++){
        int left1st = i / 10000;
        int right1st = i % 10; 
        int left2nd = (i - left1st * 10000) / 1000;
        int right2nd = (i % 100) / 10;

        if(left1st == right1st && left2nd == right2nd){
            count += 1;
        }
    }

    cout << count << endl;
}