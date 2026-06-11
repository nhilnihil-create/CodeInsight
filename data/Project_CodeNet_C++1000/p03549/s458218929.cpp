#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL n,m;
    cin >> n >> m;
    LL num = 1LL<<m;
    cout << num*m*1900+num*(n-m)*100 << endl;
    return 0;
}