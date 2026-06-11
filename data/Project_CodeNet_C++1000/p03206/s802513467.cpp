#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d;
    cin >> d;
    if(d == 25)
    {
        cout << "Christmas" << endl;
    }
    else if(d == 24)
    {
        cout << "Christmas Eve" << endl;
    }
    else if(d == 23)
    {
        cout << "Christmas Eve Eve" << endl;
    }
    else if(d == 22)
    {
        cout << "Christmas Eve Eve Eve" << endl;
    }

    return 0;
}
