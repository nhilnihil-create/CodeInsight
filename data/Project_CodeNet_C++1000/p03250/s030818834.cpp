#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int s1 = a*10 + b + c;
    int s2 = a + b*10+c;
    int s3 = c * 10 + b + a;

    cout << max(max(s1, s2), s3);
    
    return 0;
}