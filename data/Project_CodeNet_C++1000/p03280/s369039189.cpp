#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int a,b;
    cin >> a >> b;
    int road = a + b - 1;
    cout << a * b - road << endl;
}

