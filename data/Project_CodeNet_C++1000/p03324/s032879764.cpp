#include<bits/stdc++.h>
using namespace std;

int main(){
    int d, n;
    cin >> d >> n;
    if(n != 100)cout << (long long)(pow(100, d) * n) << endl;
    else cout << (long long)pow(100, d) * (n + 1) << endl;
}