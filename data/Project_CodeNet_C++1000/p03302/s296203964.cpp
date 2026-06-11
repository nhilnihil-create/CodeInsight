#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(long long a, long long b){
    if(a+b == 15) cout << '+' << endl;
    else if(a*b == 15) cout << '*' << endl;
    else cout << 'x' << endl;
}

int main(){
    long long a;
    scanf("%lld",&a);
    long long b;
    scanf("%lld",&b);
    solve(a, b);
    return 0;
}
