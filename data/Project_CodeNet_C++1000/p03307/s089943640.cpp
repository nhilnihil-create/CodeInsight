#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    unsigned long long int div = n * 2;
    if(n % 2 == 0) cout << n;
    else cout << div << endl;
    return 0;
}