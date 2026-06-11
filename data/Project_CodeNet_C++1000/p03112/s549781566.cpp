#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
long long int mpown(long long int m, int n);

int bitCount(int bits);
int main()
{
    int a, b, q;
    long long int bign=1000000000000;
    cin >> a >> b >> q;
    vector<long long int> s(a);
    vector<long long int> t(b);
    // vector<long long int> x(q);
    for (int i = 0; i < a; i++)
    {
        cin >> s.at(i);
    }
    for (int i = 0; i < b; i++)
    {
        cin >> t.at(i);
    }

    long long int inx;
    for (int j = 0; j < q; j++)
    {
        cin >> inx;
        // cout << inx << endl;
        int le = 0, ri = a - 1;
        long long int kouhos[2],kouhot[2];
        if (inx < s.at(0))
        {
            kouhos[0] = (-1) * bign;
            kouhos[1] = s.at(0);
        }
        else if (inx >= s.at(a - 1))
        {
            kouhos[0] = s.at(a - 1);
            kouhos[1] = bign;
        }
        else
        {
            while (1)
            {
                if (s.at((le + ri) / 2) <= inx)
                    le = (le + ri) / 2;
                else
                    ri = (le + ri) / 2;
                if (ri - le <= 1)
                    break;
            }
            kouhos[0] = s.at(le);
            kouhos[1] = s.at(ri);
        }

        le = 0, ri = b - 1;
        if (inx < t.at(0))
        {
            kouhot[0] = (-1) *bign;
            kouhot[1] = t.at(0);
        }
        else if(inx >= t.at(b - 1))
            {
                kouhot[0] = t.at(b - 1);
                kouhot[1] =bign;
            }
        else
        {
            while (1)
            {
                if (t.at((le + ri) / 2) <= inx)
                    le = (le + ri) / 2;
                else
                    ri = (le + ri) / 2;
                if (ri - le <= 1)
                    break;
            }
            kouhot[0] = t.at(le);
            kouhot[1] = t.at(ri);
        }
        // for(int i=0;i<2;i++){
        //     cout << kouhos[i] << "," << kouhot[i] << endl;
        // }
        long long int kouho, ans;
        ans = min(max(kouhos[1] - inx, kouhot[1] - inx), max(inx - kouhos[0], inx - kouhot[0]));

        long long int longside, shortside;
        if (inx - kouhos[0] < kouhot[1] - inx)
        {
            shortside = inx - kouhos[0];
            longside = kouhot[1] - inx;
        }else{
            longside = inx - kouhos[0];
            shortside = kouhot[1] - inx;
        }
        kouho = shortside * 2 + longside;
        if (ans > kouho)
            ans = kouho;

        if (inx - kouhot[0] < kouhos[1] - inx)
        {
            shortside = inx - kouhot[0];
            longside = kouhos[1] - inx;
        }else{
            longside = inx - kouhot[0];
            shortside = kouhos[1] - inx;
        }
        kouho = shortside * 2 + longside;
        if (ans > kouho)
            ans = kouho;

        cout << ans << endl;
    }

    return 0;
}

int bitCount(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555); //  2bitごとに計算
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333); //  4bitごとに計算
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f); //  8bitごとに計算
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff); //  16ビットごとに計算
    return (bits & 0x0000ffff) + (bits >> 16);             //  32ビット分を計算
}
long long int mpown(long long int m, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else
    {
        long long int temp = mpown(m, n / 2);
        return temp * temp * (n & 1 ? m : 1);
    }
}