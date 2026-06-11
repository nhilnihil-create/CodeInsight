#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;
long long int mpown(long long int m, int n);
long long int bign=1000000007;
int bitCount(int bits);
int main()
{
    int n,m;
    cin >> n >> m;
    int st=1,en=n;
    int l,r;
    for(int i=0;i<m;i++){
        cin >> l >> r;
        st=max(l,st);
        en=min(r,en);
    }
    if((en-st+1)>0)cout << (en-st+1) << endl;
    else cout << 0 << endl;
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