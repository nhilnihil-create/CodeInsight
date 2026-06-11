#include<bits/stdc++.h>
using namespace std;

int f(int x){
    if(x < 10) return x;
    else return x % 10 + f(x / 10);
}

int main(){
    int n, a, b, ans = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        if(a <= f(i) && f(i) <= b) ans += i;
    }
    cout << ans << endl;
    return 0;
}