#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a, b, c;
    ll k;
    cin >> a >> b >> c >> k;
    if(k % 2){
        cout << -(a - b) << endl;
    } else {
        cout << a - b << endl;
    }
    return 0;
}