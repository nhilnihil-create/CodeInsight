#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 1e9+7;

int main(){
    int a,b;
    cin>>a>>b;
    if (a <= 5){
        b = 0;
        cout << b;
    }else if (a >= 6 && a <= 12){
        cout << b/2;
    }else{
        cout << b;
    }
}