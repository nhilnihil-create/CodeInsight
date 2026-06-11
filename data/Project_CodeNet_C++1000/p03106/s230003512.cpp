#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,k,com;
    vector<int> c;
    cin >> a >> b >> k;

    if (a > b)
    {
        com = b;
    }
    else
    {
        com = a;
    }
    for (int i = 1; i <= com; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            c.push_back(i);
        }
    }
    cout << c[c.size() - k] << endl;
}   