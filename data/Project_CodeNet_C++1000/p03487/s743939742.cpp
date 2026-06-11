#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    int N;
    cin >> N;
    vector<int> a;
    int tmp;
    /*for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }*/
    map<int, int> x;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        x[tmp]++;
    }
    int ans = 0;
    for (map<int, int>::iterator i = x.begin(); i != x.end(); ++i)
    {
        if (i->first <= i->second)
        {
            ans += (i->second - i->first);
        }
        else
        {
            ans += i->second;
        }
    }
    cout << ans << endl;
    return 0;
}