#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string a, b;
    cin >> a >> b;

    bool res = true;
    for(int i = 0; i < 3; i++)if(a[i] != b[2 - i])res = false;
    cout << (res ? "YES" : "NO") << endl;
}