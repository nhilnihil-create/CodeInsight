#include <bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
    if(n < 10) 
    { 
        return n; 
    }
    return digitSum(n / 10) + n % 10; 
}


int main()
{
    int n, a, b, tmp, res = 0;
    cin >> n >> a >> b;

    for(int i = 1; i <= n; ++i)
    {
        tmp = digitSum(i);
        if(tmp >= a && tmp <= b)
        {
            res += i;
        }
    }

    cout << res << "\n";
    return 0;
}