#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int a[n],b[n];
    long long int a_sum = 0,b_sum = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        a_sum += a[i];
    }
    for(int i = 0;i < n;i++)
    {
        cin >> b[i];
        b_sum += b[i];
    }
    if(b_sum > a_sum)
    {
        cout << "-1\n";
    }
    else
    {
        vector<long long int> v;
        long long int sum = 0;
        int count = 0;
        for(int i = 0;i < n;i++)
        {
            if(a[i] - b[i] < 0)
            {
                sum += b[i] - a[i];
                count++;
            }
            else if(a[i] - b[i] > 0)
            {
                v.push_back(a[i] - b[i]);
            }
        }
        if(count == 0)
        {
            cout << "0\n";
        }
        else
        {
            sort(v.begin(),v.end(),greater<int>());
            long long int d = 0;
            int i = 0;
            while(d < sum)
            {
                d += v[i];
                i++;
            }
            cout << count + i << "\n";
        }
    }
    
    return 0;
}