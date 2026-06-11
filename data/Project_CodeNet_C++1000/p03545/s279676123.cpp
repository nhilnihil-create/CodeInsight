#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    string num;
    cin >> num;
    int a = num[0]-'0', b = num[1]-'0', c = num[2]-'0', d = num[3] - '0';

    if(a + b + c + d == 7) cout << a << "+"<<b<<"+"<<c<<"+" << d << "=7" << endl;
    else if(a - b + c + d == 7) cout << a << "-"<<b<<"+"<<c<<"+" << d << "=7" << endl;
    else if(a + b - c + d == 7) cout << a << "+"<<b<<"-"<<c<<"+" << d << "=7" << endl;
    else if(a + b + c - d == 7) cout << a << "+"<<b<<"+"<<c<<"-" << d << "=7" << endl;
    else if(a - b - c + d == 7) cout << a << "-"<<b<<"-"<<c<<"+" << d << "=7" << endl;
    else if(a - b + c - d == 7) cout << a << "-"<<b<<"+"<<c<<"-" << d << "=7" << endl;
    else if(a + b - c - d == 7) cout << a << "+"<<b<<"-"<<c<<"-" << d << "=7" << endl;
    else if(a - b - c - d == 7) cout << a << "-"<<b<<"-"<<c<<"-" << d << "=7" << endl;
}