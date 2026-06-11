#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "Hello World" << '\n';
    }
    else
    {
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}
