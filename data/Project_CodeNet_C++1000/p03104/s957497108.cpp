#include<iostream>
using ll = long long;
using namespace std;

ll xor_0_to_n(ll n)
{
    ll a = n % 4;
    if(a == 0) return n;
    else if(a == 1) return 1;
    else if(a == 2) return n + 1;
    else return 0; 
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << (xor_0_to_n(a - 1) ^ xor_0_to_n(b)) << endl;
    return 0;
}