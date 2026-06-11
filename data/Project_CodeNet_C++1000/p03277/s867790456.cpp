#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

struct bit{
    std::vector<int> v;
    int siz;

    void init(int n)
    {
        for(siz=1;siz<=n;siz<<=1);

        v.resize(siz+2);
    }
    void add(int pos, int val)
    {
        while(pos <= siz)
        {
            v[pos] += val;
            pos += (pos & -pos);
        }
    }

    int sum(int pos)
    {
        int ret = 0;
        while(pos)
        {
            ret += v[pos];
            pos -= (pos & -pos);
        }
        return ret;
    }
};
std::vector<int> x;
int n;
int t;
int check(int m)
{
    bit b;
    b.init(2*n+4);
    int pos = n+1;
    long long int ans = 1LL * n * (n+1) / 2LL;
    b.add(pos, 1);
    for(int i=0;i<n;i++)
    {
        if(x[i] >= m) pos++;
        else pos--;
        ans -= 2 * b.sum(pos);
        b.add(pos, 1);
    }
    return ans <= 0;
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &t);
        x.push_back(t);
    }
    int l = 0;
    int r = 1000000009;
    while(l < r)
    {
        int m = (l+r) / 2;
        if(check(m)) l = m+1;
        else r = m;
    }
    printf("%d", r-1);
}