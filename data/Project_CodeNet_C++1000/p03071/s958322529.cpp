#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int a,b;
    cin >> a >> b;

    int q=a+b;
    int w=a+a-1;
    int e=b+b-1;
    cout << max(max(q,w),e) << endl;

    return 0;
}