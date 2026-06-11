#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    if(a+b==15){
        puts("+");
    }
    else if(a*b == 15){
        puts("*");
    }
    else{
        puts("x");
    }
}