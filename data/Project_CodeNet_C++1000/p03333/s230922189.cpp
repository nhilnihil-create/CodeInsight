#include <bits/stdc++.h>

using namespace std;

int g[100001], l[100001], r[100001];
priority_queue <pair<int,int>> Qr;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Ql;

int main()
{
    int n, I=1, d=0, k;
    long long s=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        g[i] = 1;
        cin >> l[i] >> r[i];
        Qr.push({l[i],i});
        Ql.push({r[i],i});
    }
    I = 2;
    for (int i = 0; i < n; i++)
    {
        while (g[Ql.top().second] == 0)
        {
            Ql.pop();
        }
        while (g[Qr.top().second] == 0)
        {
            Qr.pop();
        }
        if (I == 1)
        {
            k = Ql.top().second;
            I = 2;
        }
        else
        {
            k = Qr.top().second;
            I = 1;
        }
        g[k] = 0;
        if (d < l[k])
        {
            s += l[k]-d;
            d = l[k];
        }
        else if (d > r[k])
        {
            s += d-r[k];
            d = r[k];
        }
    }
    s += abs(d);
    long long S = s;
    s = 0;
    d = 0;
    for (int i = 0; i < n; i++)
    {
        g[i] = 1;
        Qr.push({l[i],i});
        Ql.push({r[i],i});
    }
    I = 1;
    for (int i = 0; i < n; i++)
    {
        while (g[Ql.top().second] == 0)
        {
            Ql.pop();
        }
        while (g[Qr.top().second] == 0)
        {
            Qr.pop();
        }
        if (I == 1)
        {
            k = Ql.top().second;
            I = 2;
        }
        else
        {
            k = Qr.top().second;
            I = 1;
        }
        g[k] = 0;
        if (d < l[k])
        {
            s += l[k]-d;
            d = l[k];
        }
        else if (d > r[k])
        {
            s += d-r[k];
            d = r[k];
        }
    }
    s += abs(d);
    cout << max(S, s);
    return 0;
}
