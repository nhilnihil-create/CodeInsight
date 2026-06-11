#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >>b;

    int p;
    int f = 0,s = 0,t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if(p <= a)f++;
        else if(p > b)t++;
        else s++;
    }
    
    cout << min(f, min(s ,t)) << endl;
}