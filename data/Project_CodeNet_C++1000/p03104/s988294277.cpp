#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
bool chk_bit(ll n, ll k)
{
    return n & (1LL << k);
}
 
ll set_bit(ll n, ll k)
{
    return n | (1LL << k);
}
 
ll flip_bit(ll n, ll k)
{
    return n ^ (1LL << k);
}
 
ll fnc(ll n)
{
    if(n % 4 == 0) return n;
 
    if(n % 2 == 0) return (n ^ 1LL);
 
    if((n + 1) % 4 == 0) return 0LL;
 
    return 1LL;
}
 
int main()
{
    ll a, b;
 
    cin >> a >> b;
 
//    if(a == b){
//        cout << a << endl;
//        return 0;
//    }
 
    cout << (fnc(b) ^ fnc(a - 1)) << endl;
 
    return 0;
}