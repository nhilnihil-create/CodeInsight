#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll a,b;
    cin >> a >> b;
    if(a+b==15){
        cout << "+" << endl;
    }
    else if(a*b==15){
        cout << "*" << endl;
    }
    else{
        cout << "x" << endl;
    }
}