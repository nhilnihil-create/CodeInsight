#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

string s;

int cou[3];

int main()
{
    cin >> s;


    rep(i,0,2)
    {
        for(int c : s)
        {
            if(c == 'a' + i) cou[i]++;
        }
    }

    /*
    aaを避ける->何か挟む
    aba...アウト
    abca..おkk
    abba...アウト
    ->abcabcabcabcが最適
    */

    sort(cou,cou + 3);

    if(cou[2] - cou[0] <= 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}