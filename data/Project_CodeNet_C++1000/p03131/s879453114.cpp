#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k,a,b;
    cin >> k >> a >> b;
    // a->b;
    if ( (a-1)+1+1>k||b<=a+2 ) {
        cout << k+1 << '\n';
    } else {
        long long x=a;
        long long kk=k;
        kk-=(a-1); // get b biscuit
        x+=(long long)(b-a)*(kk/2);
        if ( kk%2 ) {
            x++;
        }
        cout << max(k+1,x) << '\n';
    }

    return 0;
}
