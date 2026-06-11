#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int r;
    cin >> r;
    if(r < 1200){
        cout << "ABC" << endl;
    }else if(r < 2800){
        cout << "ARC" << endl;
    }else{
        cout << "AGC" << endl;
    }
}

