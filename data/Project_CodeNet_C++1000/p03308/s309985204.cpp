#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n, a[200], mi = 0, ma = 1000000001;
    cin >> n;
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] < ma)
            ma = a[i];
        if(a[i] > mi)
            mi = a[i];
    }
    cout << mi - ma;
    return 0;
}