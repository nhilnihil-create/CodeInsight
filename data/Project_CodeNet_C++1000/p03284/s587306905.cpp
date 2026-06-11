#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

ll gcd(ll a, ll b) {
    return b ? gcd(b,a % b) : a;    
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    double n, k;
    cin >> n >> k;
    cout << (int)(ceil(n / k) - floor(n / k)) << endl;     
    return 0;
}
