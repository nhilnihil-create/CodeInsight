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
    int N;
    cin >> N;
    int p[N];
    for(int i = 0; i<N; i++) cin >> p[i];
    int Max= 0;
    int num = 0;
    for(int i = 0; i<N; i++)
    {
        if (Max < p[i])
        {
            Max = p[i];
            num = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        if(i != num) ans += p[i];
    }
    cout << ans + p[num]/2 << endl;
}