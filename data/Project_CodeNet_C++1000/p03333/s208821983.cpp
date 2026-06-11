#include <bits/stdc++.h>

#define NM 100002

using namespace std;

struct seg1
{
    int l, r;
    bool operator< (const seg1 a) const
    {
        return (this->r < a.r || (this->r == a.r && this->l < a.l));
    }
};

struct seg2
{
    int l, r;
    bool operator< (const seg2 a) const
    {
        return (this->l > a.l || (this->l == a.l && this->r > a.r));
    }
};

multiset <seg1> s1;
multiset <seg2> s2;

int n, L[NM], R[NM];

long long f(bool r)
{
    long long k = 0;
    s1.clear();
    s2.clear();
    for(int i = 1; i <= n; i++)
    {
        s1.insert({L[i], R[i]});
        s2.insert({L[i], R[i]});
    }
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        int l1, r1;
        if(i % 2 == r)
        {
            l1 = (*(s1.begin())).l;
            r1 = (*(s1.begin())).r;
            s1.erase(s1.begin());
            s2.erase(s2.find({l1, r1}));
        }
        else
        {
            l1 = (*(s2.begin())).l;
            r1 = (*(s2.begin())).r;
            s1.erase(s1.find({l1, r1}));
            s2.erase(s2.begin());
        }
        if(l1 <= pos && pos <= r1)
            continue;
        if(abs(l1 - pos) < abs(r1 - pos))
        {
            k += abs(l1 - pos);
            pos = l1;
        }
        else
        {
            k += abs(r1 - pos);
            pos = r1;
        }
    }
    k += abs(pos);
    return k;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> L[i] >> R[i];
    cout << max(f(0), f(1)) << "\n";
    return 0;
}
