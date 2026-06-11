#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int baza = 10007;
const int mod = 1e9 + 7;

map <pair <int, int>, int> imam;

long long int rj = 0;

int n;

string s, tr;

int h1, h2;

int main()
{
    cin >> n >> s;
    REP(mask, 0, (1<<n))
    {
        tr.clear();
        REP(i, 0, n)
        {
            if(mask & (1<<i))
            {
                tr.push_back(s[i]);
            }
        }
        h1 = 0;
        REP(i, 0, tr.size())
        {
            h1 = (long long) ((long long) h1 * baza + tr[i]) % mod;
        }
        tr.clear();
        REP(i, 0, n)
        {
            if(!(mask & (1<<i)))
            {
                tr.push_back(s[i]);
            }
        }
        //reverse(tr.begin(), tr.end());
        h2 = 0;
        REP(i, 0, tr.size())
        {
            h2 = (long long) ((long long) h2 * baza + tr[i]) % mod;
        }
        imam[make_pair(h1, h2)]++;
    }
    REP(mask, 0, (1<<n))
    {
        tr.clear();
        REP(i, 0, n)
        {
            if(mask & (1<<i))
            {
                tr.push_back(s[2 * n - i - 1]);
            }
        }
        h1 = 0;
        REP(i, 0, tr.size())
        {
            h1 = (long long) ((long long) h1 * baza + tr[i]) % mod;
        }
        tr.clear();
        REP(i, 0, n)
        {
            if(!(mask & (1<<i)))
            {
                tr.push_back(s[2 * n - i - 1]);
            }
        }
        //reverse(tr.begin(), tr.end());
        h2 = 0;
        REP(i, 0, tr.size())
        {
            h2 = (long long) ((long long) h2 * baza + tr[i]) % mod;
        }
        rj += imam[make_pair(h1, h2)];
    }
    cout << rj << endl;
    return 0;
}
