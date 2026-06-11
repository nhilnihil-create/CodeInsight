#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    if(n & 1) n = n / 2 + 1;
    else n /= 2;
    if(n >= k) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}