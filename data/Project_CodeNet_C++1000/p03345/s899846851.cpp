#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    long long ans = a - b;
    if(k % 2 == 1) ans = b - a;
    cout << ans << endl;
    return 0;
}