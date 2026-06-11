#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,t,x;
    cin >> a >> b >> t;
    if (a>t){
        cout << 0 << endl;
        exit(0);
    }
    x=(t-(t%a))/a;
    cout << x*b << endl;



}