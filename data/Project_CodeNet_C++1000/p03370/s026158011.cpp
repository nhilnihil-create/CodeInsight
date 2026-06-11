#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, x, a, m[200], s = 0;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
        s = s + m[i];
    }
    a = m[0];
    for(int i = 0; i < n; i++)
    {
        if(a > m[i])
            a = m[i];
    }
    cout << n + ((x - s)/a);
    return 0;
}