#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,d,g,nzd;
    cin >> n >> d;
    cin >> g;
    nzd=abs(g-d);
    for (int i=1;i<n;i++)
    {
        cin >> g;
        nzd=__gcd(nzd,abs(g-d));
    }
    cout << nzd;
}
