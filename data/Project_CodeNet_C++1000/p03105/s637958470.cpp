#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = b / a;
    cout << min(x, c);
    return 0;
}
