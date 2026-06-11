#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int maxi, mini;
    if(n > a + b)
    {
        mini = 0;
    }
    else
    {
        mini = a + b - n;
    }
    maxi = min(a, b);
    cout << maxi << " " << mini;

    return 0;

}
