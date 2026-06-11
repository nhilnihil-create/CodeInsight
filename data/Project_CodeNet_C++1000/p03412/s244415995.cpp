#include <bits/stdc++.h>

#define MAX_NR (1 << 28)

#define MAX_N 200000
#define MAX_BIT 28

using namespace std;

typedef long long lint;

int n;

int ap[MAX_N + 1];

int a[MAX_N + 1];
int b[MAX_N + 1];

int rez;

int cautBinST(int nr)
{
    int i = 0;
    int pas = 1 << 25;
    while(pas != 0)
    {
        if(i + pas <= n && ap[i + pas] < nr)
            i += pas;

        pas >>= 1;
    }

    return i + 1;
}

int cautBinDR(int nr)
{
    int i = 0;
    int pas = 1 << 25;
    while(pas != 0)
    {
        if(i + pas <= n && ap[i + pas] <= nr)
            i += pas;

        pas >>= 1;
    }

    return i;
}

int getSum(int st, int dr)
{
  //  cout << st << " -> " << dr << " ";

    int pdr = cautBinDR(dr);
    int pst = cautBinST(st);

    if(pst > pdr)
        return 0;

    return (pdr - pst + 1);
}

int main()
{
    cin >> n;

    int i, j;
    for(i = 1; i <= n; i ++)
        cin >> a[i];

    for(i = 1; i <= n; i ++)
        cin >> b[i];

    for(j = 0; j <= 28; j ++)
    {
        int r = (1 << (j + 1)) - 1;

        for(i = 1; i <= n; i ++)
            ap[i] = b[i] & r;

        sort(ap + 1, ap + n + 1);

        lint cat = 0;
        for(i = 1; i <= n; i ++)
        {
            int ant = (a[i] & r);
            int cate = getSum((1 << j) - ant, (1 << (j + 1)) - 1 - ant);
            cate += getSum((1 << j) + (1 << (j + 1)) - ant, (1 << (j + 2)) - 1 - ant);
            cat += cate;
        }

        if(cat & 1LL)
            rez += (1 << j);
    }

    cout << rez << "\n";

    return 0;
}
