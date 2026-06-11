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
    int N, Q;
    cin >> N >> Q;
    string s, tmp;
    cin >> s;
    int check[N + 1];
    fill(check, check + N + 1, 0);
    tmp = "";
    for (int i = 1; i <= N; i++)
    {
        tmp += s[i - 1];
        if (tmp.length() >= 2)
        {
            if (tmp[tmp.length() - 2] == 'A' && tmp[tmp.length() - 1] == 'C')
            {
                check[i] = check[i - 1] + 1;
            }
            else
            {
                check[i] = check[i - 1];
            }
        }
    }
    int l[Q], r[Q];
    for (int i = 0; i < Q; i++)
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < Q; i++)
    {
        cout << check[r[i]] - check[l[i]] << endl;
    }
    return 0;
}
