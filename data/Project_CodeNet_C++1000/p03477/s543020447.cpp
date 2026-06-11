#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int sum1 = a+b;
    int sum2 = c+d;
    if(sum1>sum2) cout << "Left" << endl;
    else if( sum1<sum2) cout << "Right" << endl;
    else cout << "Balanced" << endl;
    return 0;
}