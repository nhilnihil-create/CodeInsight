#include <bits/stdc++.h>
using namespace std;
#define LL long int

const LL MOD = pow(10,9) + 7;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a > b) swap(a,b);
    if(a <= c && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}