#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
using namespace std;


int main()
{
    int N,T;
    cin >> N >> T;
    int c[N],t[N];
    for(int i = 0; i < N; i++)
    {
        cin >> c[i];
        cin >> t[i];
    }
    int res = 1001;
    for(int i = 0; i < N; i++)
    {
        if(t[i] <= T)
        {
            res = min(res,c[i]);
        }
    }
    if (res == 1001)
    {
        cout << "TLE" << endl;
    }
    else cout << res << endl;
}