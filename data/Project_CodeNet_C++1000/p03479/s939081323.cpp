#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t X, Y;
    cin >> X >> Y;
    int64_t Z = Y/X;
    int64_t i = 1;
    int count = 0;
    while (Z>=i){
        i *= 2;
        count ++;
    }
    cout << count << endl;
}