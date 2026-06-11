#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x,y;
    cin >> x >> y;

    long long res = (x * y) / __gcd(x,y);
    if(res == x) cout << -1; else cout << res - x << endl;

}

