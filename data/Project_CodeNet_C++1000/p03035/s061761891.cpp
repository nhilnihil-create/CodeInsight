#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b;
    cin >> a >> b;
    if(a >= 13){
        cout << b << endl;
    }
    else if((6 <= a) && (a <= 12)){
        cout << b/2 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}