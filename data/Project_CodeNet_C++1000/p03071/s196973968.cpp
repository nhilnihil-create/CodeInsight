#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, sum;
    cin >> a >> b;
    sum=max(a, b);
    if(a>b)a--;
    else  b--;
    sum+=max(a, b);
    cout << sum;
}
