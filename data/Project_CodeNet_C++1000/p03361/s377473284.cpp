#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }



int main()
{
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int H,W;
    cin >> H >> W;
    char s[H][W];
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> s[i][j];
        }
    }
    bool flag = false;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            flag = false;
            if(s[i][j] == '#')
            {
                for(int k = 0; k < 4; k++)
                {
                    if(i + dx[k] <= H - 1 && i + dx[k] >= 0 && j + dy[k] <= W - 1 && j + dy[k] >= 0)
                    {
                        if(s[i + dx[k]][j + dy[k]] == '#')
                        {
                            flag = true;
                        }

                    }
                }
                if(flag == false)
                {
                    cout << "No" << endl;
                    return(0);
                }
            }
        }
    }
    cout << "Yes" << endl;

}