#include <bits/stdc++.h>
using namespace std;
int main(){
    int d, n;
    cin >> d >> n;
    if (n != 100){
        cout << (long long int) (pow(100, d) * n) << endl;
    }
    else{cout << (int) pow(100, d) * 101 << endl;}
    return 0;
}