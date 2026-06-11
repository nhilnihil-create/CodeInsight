#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
int main()
{
    ll n;
    cin >> n;
    ll pt = sqrt(n);
    cout << pt * pt << endl;

    return 0;
}
