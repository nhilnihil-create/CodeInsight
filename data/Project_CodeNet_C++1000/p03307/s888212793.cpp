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
    int n;
    cin >> n;
    int ans = n;
    if(n % 2 == 1) ans *= 2;
    cout << ans << endl;
    return 0;
}