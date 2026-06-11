#include<iostream>
using namespace std;
int main()
{
    int n, T, a, b;
    cin >> n >> T;
    int c[n], t[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i] >> t[i];
    }

    for(int j = 0; j < n; j++)
    {
        for(int i = j; i < n; i++)
        {
            if(c[j] > c[i])
            {
                a = c[j];
                c[j] = c[i];
                c[i] = a;
                b = t[j];
                t[j] = t[i];
                t[i] = b;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(t[i] <= T)
        {
            cout << c[i];
            return 0;
        }
    }
    cout << "TLE";
    return 0;
}