#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, r1, r2, r3, r4, r5, r6, r7, r8, r9, sum;
    cin >> n;
    r1 = n%10;
    r2 = (n%100)/10;
    r3 = (n%1000)/100;
    r4 = (n%10000)/1000;
    r5 = (n%100000)/10000;
    r6 = (n%1000000)/100000;
    r7 = (n%10000000)/1000000;
    r8 = (n%100000000)/10000000;
    r9 = (n%1000000000)/100000000;
    sum = r1+r2+r3+r4+r5+r6+r7+r8+r9;
    if((n % sum) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}