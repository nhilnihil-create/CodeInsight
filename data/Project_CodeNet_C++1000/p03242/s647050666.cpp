#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    string n;
    cin >> n;
    for(int i = 0;i < n.length();i++){
        if(n[i] == '1'){
            n[i] = '9';
        }else{
            n[i] = '1';
        }
    }
    cout << n << endl;
}

