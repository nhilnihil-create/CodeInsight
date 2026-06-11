#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
#include <cstdlib>
#include <map>
using ll = long long int;
using namespace std;

int main()
{
    int N, H, W, ans = 0;
    cin >> N >> H >> W;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if ((H <= a) && (W <= b))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}