#define _USE_MATH_DEFINES
#include <math.h>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    long long int count1 = 0,count2 = 0;
    for(int i = 1;i <= n;i++)
    {
        if(i % k == 0)
        {
            count1++;
        }
        else if(i % k == k / 2)
        {
            count2++;
        }
    }
    if(k % 2 == 0)
    {
        cout << count1 * count1 * count1 + count2 * count2 * count2 << "\n";
    }
    else
    {
        cout << count1 * count1 * count1 << "\n";
    }
    
    return 0;
}