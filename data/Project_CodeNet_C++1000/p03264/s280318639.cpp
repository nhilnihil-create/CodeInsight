#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll n, a, b;
    cin >> n;
    if(n%2) cout << (n/2)*(n/2 + 1) << endl;
    else cout << (n/2)*(n/2) << endl;
    return 0;
}