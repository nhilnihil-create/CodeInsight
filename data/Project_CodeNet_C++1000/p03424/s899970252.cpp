#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    map<string, int> a;
    int N;
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        a[s]++;
    }
    if (a.size() == 3)
    {
        cout << "Three" << endl;
    }
    else
    {
        cout << "Four" << endl;
    }
    return 0;
}
