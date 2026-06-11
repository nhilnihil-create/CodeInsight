#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll mod = 1000000007;


int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d) ? "Yes" : "No") << endl;
}