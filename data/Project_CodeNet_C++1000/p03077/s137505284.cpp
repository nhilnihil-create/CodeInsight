#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long min;
    cin >> min;
    for(int i =1; i < 5; i++){
        long long x;
        cin >> x;
        if(x < min) min = x;
    } 
    cout << 4 + (min-1 + n)/min << endl;
}