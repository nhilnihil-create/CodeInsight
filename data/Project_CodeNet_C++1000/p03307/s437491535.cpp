#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a,ll b){while(a&&b){if(a>b) a = a%b;else b = b%a;}return a+b;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}

int main()
{
    int n; cin >> n;
    cout << lcm(n, 2) << endl;
}