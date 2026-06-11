#include <bits/stdc++.h>
using namespace std;


int main()
{
    double n,m,d;
    cin >> n >> m >> d;
    double res = (n-d)*(m-1)*(d>0.5?2:1)/(n*n);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}