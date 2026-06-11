#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
using namespace std;
typedef long long int lli;
int main(void)
{
    int N;
    cin >> N;
    int *a;
    a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int cnt = 1;
    int cnt2 = 1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] % 2 == 0)
        {
            cnt2 *= 2;
        }
        cnt *= 3;
    }
    int ans = cnt - cnt2;
    cout << ans << endl;
    return 0;
}