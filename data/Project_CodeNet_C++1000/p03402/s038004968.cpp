#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <sstream>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)

int main()
{    
    int a,b;
    cin >> a >> b;

    stringstream ss;
    int h = 0;
    int w = 100;
    int ra = a-1;
    int rb = b-1;
    rep(i,25)
    {
        rep(j,50)
        {
            if(j%2==0 && rb>0)
            {
                ss << "#";
                rb--;
            }
            else
                ss << ".";
        }

        rep(j,50)
        {
            if(j%2==1 && ra>0)
            {
                ss << ".";
                ra--;
            }
            else
                ss << "#";
        }

        ss << endl;
        rep(j,50) ss << ".";
        rep(j,50) ss << "#";
        ss << endl;

        h += 2;
        if(ra<=0 && rb<=0) break;
    }

    cout << h << " " << w << endl << ss.str();
    return 0;
}