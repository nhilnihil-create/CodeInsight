#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a,b,c,d,e;
    int dmax;
    cin >> a >> b >> c >> d >> e;
    cin >> dmax;
    if(e - a > dmax)
    {
        cout << ":(\n";
    }
    else
    {
        cout << "Yay!" << endl;
    }
    return 0;
}