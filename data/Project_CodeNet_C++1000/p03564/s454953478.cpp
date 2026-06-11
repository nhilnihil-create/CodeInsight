#include <bits/stdc++.h>
using namespace std;

int main()
{

    int num = 1;
    int n,k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        if(num * 2 < num + k)
        {
            num *= 2;
        }
        else
        {
            num += k;
        }
    }
    cout << num << endl;

    return 0;
}