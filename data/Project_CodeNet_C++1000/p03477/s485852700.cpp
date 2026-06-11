#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a + b == c + d)
        cout << "Balanced" << endl;
    else if(a + b > c + d)
        cout << "Left" << endl;
    else
        cout << "Right" << endl;
    return 0;
}
