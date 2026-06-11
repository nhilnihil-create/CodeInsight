#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int main()
{
    int a,b,c,d,e,k;
    cin >> a >> b >> c >> d >> e >> k;
    if(k >= e - a)
    {
        cout << "Yay!" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
    return 0;
}