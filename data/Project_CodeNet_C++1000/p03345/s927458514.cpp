#include <bits/stdc++.h>
using namespace std;

int a, b, c;
long long k;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> k;
    if(k & 1){
        cout << b - a << endl;
    }else{
        cout << a - b << endl;
    }
    return 0;
}
