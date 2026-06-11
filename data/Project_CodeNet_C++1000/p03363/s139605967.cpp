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
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N;
    cin >> N;
    lli a[N];
    lli b[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    fill(b, b + N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        b[i] = b[i - 1] + a[i - 1];
    }
    lli cnt = 0;
    sort(b, b + N + 1);
    map<lli, lli> x;
    for (int i = 0; i <= N; i++)
    {
        x[b[i]]++;
    }
    //for (map<lli, lli>::iterator y = x.begin(); y != x.end(); ++y)
    for (auto it : x)
    {
        cnt += it.second * (it.second - 1) / 2;
    }
    cout << cnt << endl;
    return 0;
}
