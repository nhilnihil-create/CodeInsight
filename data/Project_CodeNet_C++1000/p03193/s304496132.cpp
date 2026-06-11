#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
struct sqe
{
    lli A;
    lli B;
};
int main(void)
{
    lli N, H, W;
    cin >> N >> H >> W;
    sqe *ita;
    ita = new sqe [N];
    for (int i = 0; i < N; i++)
    {
        cin >> ita[i].A >> ita[i].B;
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (ita[i].A >= H && ita[i].B >= W)
        {
            count++;
        }
    }
  	cout << count <<endl;
    return 0;
}