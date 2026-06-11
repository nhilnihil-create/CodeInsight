#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;


int main()
{
    int a, b;
    cin >> a >> b;
    cout << (b % a ? b - a : b + a) << endl;
}