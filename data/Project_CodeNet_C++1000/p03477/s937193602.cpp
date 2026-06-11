#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a+b > c+d)
        cout << "Left" << endl;
    else if(a+b < c+d)
        cout << "Right" << endl;
    else
        cout << "Balanced" << endl;

    return 0;
}
