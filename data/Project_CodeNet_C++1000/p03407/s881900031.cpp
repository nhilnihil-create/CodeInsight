#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b >= c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

