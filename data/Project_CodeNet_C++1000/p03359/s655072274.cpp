#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    int a, b;
    cin >> a >> b;
    if(b < a)
        cout << a - 1 << endl;
    else
        cout << a << endl;
    return 0;
}
