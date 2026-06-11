#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int totalAntidote = a + b;
    if(totalAntidote + 1 >= c) cout << b + c << endl;
    else cout << totalAntidote + b + 1 << endl;
    return 0;
}
