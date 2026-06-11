#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int A, B;
    cin >> A >> B;

    int ans = max({A + B, A - B, A * B});
    cout << ans << endl;
    return (0);
}