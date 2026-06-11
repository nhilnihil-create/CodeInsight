#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    int a, n;
    cin >> n >> a;
    if(n % 500 <= a)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
