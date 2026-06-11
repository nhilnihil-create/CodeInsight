#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c; cin >> a >> b >> c;

    int total =  b / a;

    if(total > c)
        cout << c << endl;
    else
        cout << total << endl;
    

    return 0;
}